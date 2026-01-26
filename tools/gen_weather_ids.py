#!/usr/bin/env python3
import os
import re
import sys
from pathlib import Path
from collections import defaultdict, namedtuple

# --------------------------------------------------------------------
# Paths (adjust if your layout differs)
# --------------------------------------------------------------------

REPO_ROOT = Path(__file__).resolve().parents[1]

INC_PATH          = REPO_ROOT / "data" / "weather_ids.inc"
OUT_S_PATH        = REPO_ROOT / "data" / "weather_ids.s"
REPORT_PATH       = REPO_ROOT / "data" / "maps" / "weather" / "weather_report.txt"
MAP_GROUPS_PATH   = REPO_ROOT / "include" / "constants" / "map_groups.h"
WEATHER_TABLES_INC = REPO_ROOT / "data" / "weather_tables.inc"

WEATHER_ID_PREFIX = "WEATHER_ID_"
MAP_PREFIX        = "MAP_"
WEATHER_TABLE_PREFIX = "WeatherTable_"

Entry = namedtuple("Entry", ["map_macro", "weather_id_macro", "cluster_id", "region_letter", "cluster_num"])


# --------------------------------------------------------------------
# Utility: logging
# --------------------------------------------------------------------

warnings_list = []

def warn(msg: str):
    warnings_list.append(msg)
    print(f"[weather-gen WARNING] {msg}", file=sys.stderr)


# --------------------------------------------------------------------
# Parse weather_ids.inc
# --------------------------------------------------------------------

def parse_weather_ids(inc_path: Path):
    """
    Parse lines like:
        #define WEATHER_ID_ROUTE28              Y0
    into Entry(map_macro='MAP_ROUTE28', weather_id_macro='WEATHER_ID_ROUTE28',
               cluster_id='Y0', region_letter='Y', cluster_num=0)
    """
    entries = []
    seen_weather_ids = set()
    seen_maps = set()

    define_re = re.compile(r"^#define\s+(\w+)\s+([A-Z][0-9])\s*$")

    with inc_path.open("r", encoding="utf-8") as f:
        for lineno, line in enumerate(f, 1):
            line_stripped = line.strip()
            if not line_stripped.startswith("#define"):
                continue

            m = define_re.match(line_stripped)
            if not m:
                # Not a WEATHER_ID_* with X0-style cluster, skip
                continue

            macro_name, cluster_id = m.groups()
            if not macro_name.startswith(WEATHER_ID_PREFIX):
                continue

            weather_id_macro = macro_name
            map_suffix = macro_name[len(WEATHER_ID_PREFIX):]
            map_macro = f"{MAP_PREFIX}{map_suffix}"

            region_letter = cluster_id[0]
            try:
                cluster_num = int(cluster_id[1])
            except ValueError:
                warn(f"{inc_path}:{lineno}: invalid cluster id '{cluster_id}' for {weather_id_macro}")
                cluster_num = -1

            if weather_id_macro in seen_weather_ids:
                warn(f"{inc_path}:{lineno}: duplicate WEATHER_ID macro {weather_id_macro}")
            seen_weather_ids.add(weather_id_macro)

            if map_macro in seen_maps:
                warn(f"{inc_path}:{lineno}: duplicate map entry for {map_macro}")
            seen_maps.add(map_macro)

            entries.append(Entry(
                map_macro=map_macro,
                weather_id_macro=weather_id_macro,
                cluster_id=cluster_id,
                region_letter=region_letter,
                cluster_num=cluster_num,
            ))

    if not entries:
        warn(f"No WEATHER_ID_* definitions with cluster IDs found in {inc_path}")

    return entries


# --------------------------------------------------------------------
# Parse map_groups.h to get all valid MAP_* names
# --------------------------------------------------------------------

def parse_map_groups(map_groups_path: Path):
    """
    Parse lines like:
        #define MAP_ROUTE28 (13 | (43 << 8))
    into a dict: { 'MAP_ROUTE28': (group, num), ... }
    """
    maps = {}
    define_re = re.compile(r"^#define\s+(MAP_\w+)\s+\((\d+)\s*\|\s*\((\d+)\s*<<\s*8\)\s*\)")

    with map_groups_path.open("r", encoding="utf-8") as f:
        for lineno, line in enumerate(f, 1):
            line_stripped = line.strip()
            if not line_stripped.startswith("#define"):
                continue
            m = define_re.match(line_stripped)
            if not m:
                continue
            name, num_str, group_str = m.groups()
            try:
                num = int(num_str)
                group = int(group_str)
            except ValueError:
                warn(f"{map_groups_path}:{lineno}: could not parse group/num for {name}")
                continue
            maps[name] = (group, num)

    if not maps:
        warn(f"No MAP_* definitions parsed from {map_groups_path}")

    return maps


# --------------------------------------------------------------------
# Parse weather_tables.inc to find defined WeatherTable_* labels
# --------------------------------------------------------------------

def parse_weather_tables(weather_tables_path: Path):
    """
    Look for labels like:
        WeatherTable_X0:
        WeatherTable_Y3:
    and return a set of cluster IDs like {'X0', 'Y3', ...}
    """
    if not weather_tables_path.is_file():
        warn(f"{weather_tables_path} not found; cluster table validation will be limited")
        return set()

    tables = set()
    label_re = re.compile(rf"^{WEATHER_TABLE_PREFIX}([A-Z][0-9]):\s*$")

    with weather_tables_path.open("r", encoding="utf-8") as f:
        for lineno, line in enumerate(f, 1):
            line_stripped = line.strip()
            m = label_re.match(line_stripped)
            if not m:
                continue
            cluster_id = m.group(1)
            tables.add(cluster_id)

    if not tables:
        warn(f"No {WEATHER_TABLE_PREFIX}* labels found in {weather_tables_path}")

    return tables


# --------------------------------------------------------------------
# Validation and reporting
# --------------------------------------------------------------------

def validate_entries(entries, map_defs, cluster_tables):
    """
    Perform all the requested validations:
      - WEATHER_ID_* → MAP_* exists
      - warn about maps in game with no weather entry
      - warn about unused clusters
      - warn about clusters referenced but no table
    """
    # 1. WEATHER_ID_* → MAP_* exists
    used_clusters = set()
    used_maps = set()

    for e in entries:
        used_clusters.add(e.cluster_id)
        used_maps.add(e.map_macro)
        if e.map_macro not in map_defs:
            warn(f"{e.map_macro} (from {e.weather_id_macro}) does not exist in {MAP_GROUPS_PATH}")

    # 2. Warn about maps that exist but have no weather entry
    for map_name in sorted(map_defs.keys()):
        if not map_name.startswith(MAP_PREFIX):
            continue
        if map_name not in used_maps:
            warn(f"{map_name} exists in {MAP_GROUPS_PATH} but has no WEATHER_ID entry in {INC_PATH}")

    # 3. Unused clusters (tables defined but no maps use them)
    if cluster_tables:
        unused_clusters = sorted(cluster_tables - used_clusters)
        for cid in unused_clusters:
            warn(f"Cluster {cid} has a {WEATHER_TABLE_PREFIX}{cid} table but no maps assigned")

    # 4. Clusters referenced but no table
    if cluster_tables:
        missing_tables = sorted(used_clusters - cluster_tables)
        for cid in missing_tables:
            warn(f"Cluster {cid} is used by maps but has no {WEATHER_TABLE_PREFIX}{cid} table defined")


def group_entries(entries):
    """
    Group entries by cluster_id, then sort clusters and maps.
    Returns an ordered list of (cluster_id, [entries...]).
    """
    by_cluster = defaultdict(list)
    for e in entries:
        by_cluster[e.cluster_id].append(e)

    # Sort maps within each cluster by map_macro
    for cid in by_cluster:
        by_cluster[cid].sort(key=lambda e: e.map_macro)

    # Sort clusters by region letter then cluster number
    def cluster_sort_key(cid):
        return (cid[0], int(cid[1]))

    ordered_clusters = sorted(by_cluster.keys(), key=cluster_sort_key)
    return [(cid, by_cluster[cid]) for cid in ordered_clusters]


def write_report(report_path: Path, grouped_entries, map_defs, cluster_tables):
    """
    Write a human-readable audit report.
    """
    lines = []
    lines.append("Weather System Report")
    lines.append("=====================")
    lines.append("")
    lines.append(f"Source: {INC_PATH}")
    lines.append(f"Map groups: {MAP_GROUPS_PATH}")
    lines.append(f"Weather tables: {WEATHER_TABLES_INC}")
    lines.append("")
    lines.append("Clusters and maps:")
    lines.append("------------------")
    lines.append("")

    for cid, entries in grouped_entries:
        lines.append(f"Cluster {cid}:")
        for e in entries:
            group_num = map_defs.get(e.map_macro, ("?", "?"))
            lines.append(f"  {e.map_macro}  (group={group_num[0]}, num={group_num[1]})  <- {e.weather_id_macro}")
        lines.append("")

    lines.append("")
    lines.append("Warnings:")
    lines.append("---------")
    if warnings_list:
        for w in warnings_list:
            lines.append(f"- {w}")
    else:
        lines.append("None.")
    lines.append("")

    report_path.parent.mkdir(parents=True, exist_ok=True)
    with report_path.open("w", encoding="utf-8") as f:
        f.write("\n".join(lines))


# --------------------------------------------------------------------
# Emit weather_ids.s
# --------------------------------------------------------------------

def write_asm(out_path: Path, grouped_entries):
    """
    Emit an .s file that:
      - includes weather_ids.inc (for the WEATHER_ID_* macros)
      - defines gMapWeatherIds as a sequence of:
            .byte (MAP_FOO >> 8), (MAP_FOO & 0xFF), WEATHER_ID_FOO
      - terminates with 0xFF, 0xFF, 0x00
    Grouped by cluster for readability.
    """
    lines = []

    lines.append("    .section .rodata")
    lines.append("    .align 2")
    lines.append("")
    lines.append('    .include "data/maps/weather/weather_ids.inc"')
    lines.append("")
    lines.append("    .global gMapWeatherIds")
    lines.append("gMapWeatherIds:")
    lines.append("")

    current_region = None
    for cid, entries in grouped_entries:
        region_letter = cid[0]
        if region_letter != current_region:
            current_region = region_letter
            lines.append(f"    @ ================= Region {region_letter} =================")
        lines.append(f"    @ Cluster {cid}")
        for e in entries:
            lines.append(
                f"    .byte ({e.map_macro} >> 8), ({e.map_macro} & 0xFF), {e.weather_id_macro}"
            )
        lines.append("")

    lines.append("")
    # Terminator: mapGroup = 0xFF, mapNum = 0xFF, weatherId = 0x00
    lines.append("    .byte 0xFF, 0xFF, 0x00")
    lines.append("")

    out_path.parent.mkdir(parents=True, exist_ok=True)
    with out_path.open("w", encoding="utf-8") as f:
        f.write("\n".join(lines))


# --------------------------------------------------------------------
# Main
# --------------------------------------------------------------------

def main():
    # Core existence checks (these can fail the build)
    if not INC_PATH.is_file():
        print(f"error: weather_ids.inc not found at {INC_PATH}", file=sys.stderr)
        sys.exit(1)
    if not MAP_GROUPS_PATH.is_file():
        print(f"error: map_groups.h not found at {MAP_GROUPS_PATH}", file=sys.stderr)
        sys.exit(1)

    entries = parse_weather_ids(INC_PATH)
    map_defs = parse_map_groups(MAP_GROUPS_PATH)
    cluster_tables = parse_weather_tables(WEATHER_TABLES_INC)

    # Perform validations (only warnings, no hard failures)
    validate_entries(entries, map_defs, cluster_tables)

    # Group and sort
    grouped_entries = group_entries(entries)

    # Emit outputs
    write_asm(OUT_S_PATH, grouped_entries)
    write_report(REPORT_PATH, grouped_entries, map_defs, cluster_tables)

    # Never fail the build because of warnings
    if warnings_list:
        print(f"[weather-gen] Completed with {len(warnings_list)} warning(s).", file=sys.stderr)
    else:
        print("[weather-gen] Completed with no warnings.", file=sys.stderr)

    sys.exit(0)


if __name__ == "__main__":
    main()
