#!/bin/bash

echo "=== Running map audit ==="

for d in data/maps/*/; do
    m=$(basename "$d")
    echo
    echo "=== $m ==="

    # Check map.json exists
    if [ ! -f "$d/map.json" ]; then
        echo "ERROR: map.json missing"
        continue
    fi

    # Check map.json is valid JSON
    if ! jq empty "$d/map.json" >/dev/null 2>&1; then
        echo "ERROR: map.json is invalid JSON"
        continue
    fi

    # Check scripts.inc exists
    if [ ! -f "$d/scripts.inc" ]; then
        echo "ERROR: scripts.inc missing"
        continue
    fi

    # Check text.inc exists
    if [ ! -f "$d/text.inc" ]; then
        echo "ERROR: text.inc missing"
        continue
    fi

    # Check layout field exists
    if ! jq -e '.layout' "$d/map.json" >/dev/null 2>&1; then
        echo "ERROR: layout field missing in map.json"
        continue
    fi

    echo "OK"
done

echo
echo "=== Audit complete ==="
