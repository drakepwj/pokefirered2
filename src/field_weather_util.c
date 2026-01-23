#include "global.h"
#include "field_weather.h"
#include "overworld.h"
#include "constants/weather.h"


// ======================
// Climate Engine
//======================

enum {
    REGION_X,
    REGION_Y,
    REGION_Z,
    REGION_C,
    REGION_I,
    REGION_S,
    REGION_V,
    REGION_COUNT
};

struct RegionFamilyEntry {
    u8 mapGroup;
    u8 mapNum;
    u8 regionFamily;
};

static const struct RegionFamilyEntry sRegionFamilyTable[] = {

    // ============================================================
    // ======================= JOHTO NORTH (REGION_Y) ==============
    // ============================================================

    { MAP_GROUP_ROUTE28,            MAP_NUM_ROUTE28,            REGION_Y },
    { MAP_GROUP_MTSILVER_EXTERIOR,  MAP_NUM_MTSILVER_EXTERIOR,  REGION_Y },
    { MAP_GROUP_MTSILVER_SUMMIT,    MAP_NUM_MTSILVER_SUMMIT,    REGION_Y },

    // Ice Path (forced outdoor)
    { MAP_GROUP_ICEPATH_1F,         MAP_NUM_ICEPATH_1F,         REGION_Y },
    { MAP_GROUP_ICEPATH_B1F,        MAP_NUM_ICEPATH_B1F,        REGION_Y },
    { MAP_GROUP_ICEPATH_B2F,        MAP_NUM_ICEPATH_B2F,        REGION_Y },
    { MAP_GROUP_ICEPATH_B3F,        MAP_NUM_ICEPATH_B3F,        REGION_Y },

    { MAP_GROUP_MAHOGANYTOWN,       MAP_NUM_MAHOGANYTOWN,       REGION_Y },
    { MAP_GROUP_ROUTE44,            MAP_NUM_ROUTE44,            REGION_Y },

    { MAP_GROUP_ROUTE43,            MAP_NUM_ROUTE43,            REGION_Y },
    { MAP_GROUP_LAKEOFRAGE,         MAP_NUM_LAKEOFRAGE,         REGION_Y },

    { MAP_GROUP_BLACKTHORNCITY,     MAP_NUM_BLACKTHORNCITY,     REGION_Y },
    { MAP_GROUP_BLACKTHORN_GYM,     MAP_NUM_BLACKTHORN_GYM,     REGION_Y },

    { MAP_GROUP_ROUTE45,            MAP_NUM_ROUTE45,            REGION_Y },


    // ============================================================
    // ======================= JOHTO WEST (REGION_X) ===============
    // ============================================================

    { MAP_GROUP_ROUTE42,            MAP_NUM_ROUTE42,            REGION_X },
    { MAP_GROUP_ECRUTEAKCITY,       MAP_NUM_ECRUTEAKCITY,       REGION_X },
    { MAP_GROUP_BURNEDTOWER_1F,     MAP_NUM_BURNEDTOWER_1F,     REGION_X },

    { MAP_GROUP_PEACHWOODTOWN,      MAP_NUM_PEACHWOODTOWN,      REGION_X },

    { MAP_GROUP_ROUTE38,            MAP_NUM_ROUTE38,            REGION_X },
    { MAP_GROUP_ROUTE39,            MAP_NUM_ROUTE39,            REGION_X },

    { MAP_GROUP_OLIVINECITY,        MAP_NUM_OLIVINECITY,        REGION_X },
    { MAP_GROUP_ROUTE40,            MAP_NUM_ROUTE40,            REGION_X },

    { MAP_GROUP_WHIRLISLANDS_EXT,   MAP_NUM_WHIRLISLANDS_EXT,   REGION_X },
    { MAP_GROUP_ROUTE41,            MAP_NUM_ROUTE41,            REGION_X },

    { MAP_GROUP_CIANWOODCITY,       MAP_NUM_CIANWOODCITY,       REGION_X },
    { MAP_GROUP_CIANWOOD_GYM,       MAP_NUM_CIANWOOD_GYM,       REGION_X },

    { MAP_GROUP_ROUTE47,            MAP_NUM_ROUTE47,            REGION_X },
    { MAP_GROUP_ROUTE48,            MAP_NUM_ROUTE48,            REGION_X },

    { MAP_GROUP_ROUTE49,            MAP_NUM_ROUTE49,            REGION_X },
    { MAP_GROUP_ROUTE50,            MAP_NUM_ROUTE50,            REGION_X },

    { MAP_GROUP_BLEAKRESTCOVE,      MAP_NUM_BLEAKRESTCOVE,      REGION_X },
    { MAP_GROUP_OBSIDIANCITY,       MAP_NUM_OBSIDIANCITY,       REGION_X },


    // ============================================================
    // ======================= JOHTO SOUTH (REGION_Z) ==============
    // ============================================================

    { MAP_GROUP_NEWBARKTOWN,        MAP_NUM_NEWBARKTOWN,        REGION_Z },
    { MAP_GROUP_ROUTE29,            MAP_NUM_ROUTE29,            REGION_Z },

    { MAP_GROUP_ROUTE31,            MAP_NUM_ROUTE31,            REGION_Z },
    { MAP_GROUP_VIOLETCITY,         MAP_NUM_VIOLETCITY,         REGION_Z },

    { MAP_GROUP_ROUTE32,            MAP_NUM_ROUTE32,            REGION_Z },

    { MAP_GROUP_ROUTE33,            MAP_NUM_ROUTE33,            REGION_Z },
    { MAP_GROUP_AZALEATOWN,         MAP_NUM_AZALEATOWN,         REGION_Z },

    { MAP_GROUP_ILEXFOREST,         MAP_NUM_ILEXFOREST,         REGION_Z },

    { MAP_GROUP_ROUTE34,            MAP_NUM_ROUTE34,            REGION_Z },
    { MAP_GROUP_GOLDENRODCITY,      MAP_NUM_GOLDENRODCITY,      REGION_Z },

    { MAP_GROUP_ROUTE35,            MAP_NUM_ROUTE35,            REGION_Z },
    { MAP_GROUP_NATIONALPARK,       MAP_NUM_NATIONALPARK,       REGION_Z },
    { MAP_GROUP_ROUTE36,            MAP_NUM_ROUTE36,            REGION_Z },
    { MAP_GROUP_ROUTE37,            MAP_NUM_ROUTE37,            REGION_Z },

    { MAP_GROUP_RUINSOFALPH_OUTSIDE, MAP_NUM_RUINSOFALPH_OUTSIDE, REGION_Z },

    { MAP_GROUP_ROUTE46,            MAP_NUM_ROUTE46,            REGION_Z },

    { MAP_GROUP_ROUTE30,            MAP_NUM_ROUTE30,            REGION_Z },
    { MAP_GROUP_CHERRYGROVECITY,    MAP_NUM_CHERRYGROVECITY,    REGION_Z },


    // ============================================================
    // ===================== KANTO COASTAL (REGION_C) =============
    // ============================================================

    { MAP_GROUP_VIRIDIANCITY,       MAP_NUM_VIRIDIANCITY,       REGION_C },
    { MAP_GROUP_ROUTE1,             MAP_NUM_ROUTE1,             REGION_C },
    { MAP_GROUP_PALLETTOWN,         MAP_NUM_PALLETTOWN,         REGION_C },

    { MAP_GROUP_ROUTE21,            MAP_NUM_ROUTE21,            REGION_C },
    { MAP_GROUP_ROUTE20,            MAP_NUM_ROUTE20,            REGION_C },
    { MAP_GROUP_CINNABARISLAND,     MAP_NUM_CINNABARISLAND,     REGION_C },

    { MAP_GROUP_ROUTE19,            MAP_NUM_ROUTE19,            REGION_C },
    { MAP_GROUP_FUCHSIACITY,        MAP_NUM_FUCHSIACITY,        REGION_C },

    { MAP_GROUP_ROUTE13,            MAP_NUM_ROUTE13,            REGION_C },
    { MAP_GROUP_ROUTE14,            MAP_NUM_ROUTE14,            REGION_C },
    { MAP_GROUP_ROUTE15,            MAP_NUM_ROUTE15,            REGION_C },

    { MAP_GROUP_ROUTE12,            MAP_NUM_ROUTE12,            REGION_C },

    { MAP_GROUP_ROUTE11,            MAP_NUM_ROUTE11,            REGION_C },
    { MAP_GROUP_VERMILIONCITY,      MAP_NUM_VERMILIONCITY,      REGION_C },
    { MAP_GROUP_ROUTE6,             MAP_NUM_ROUTE6,             REGION_C },

    { MAP_GROUP_ROUTE16,            MAP_NUM_ROUTE16,            REGION_C },
    { MAP_GROUP_ROUTE17,            MAP_NUM_ROUTE17,            REGION_C },
    { MAP_GROUP_ROUTE18,            MAP_NUM_ROUTE18,            REGION_C },

    { MAP_GROUP_SEAFOAM_EXT,        MAP_NUM_SEAFOAM_EXT,        REGION_C },

    { MAP_GROUP_SAFARIZONE_EXT,     MAP_NUM_SAFARIZONE_EXT,     REGION_C },

    // ============================================================
    // ===================== KANTO INLAND (REGION_I) ==============
    // ============================================================

    { MAP_GROUP_PEWTERCITY,         MAP_NUM_PEWTERCITY,         REGION_I },
    { MAP_GROUP_ROUTE2,             MAP_NUM_ROUTE2,             REGION_I },
    { MAP_GROUP_ROUTE3,             MAP_NUM_ROUTE3,             REGION_I },

    { MAP_GROUP_VIRIDIANFOREST,     MAP_NUM_VIRIDIANFOREST,     REGION_I },

    { MAP_GROUP_CERULEANCITY,       MAP_NUM_CERULEANCITY,       REGION_I },
    { MAP_GROUP_ROUTE4,             MAP_NUM_ROUTE4,             REGION_I },
    { MAP_GROUP_ROUTE24,            MAP_NUM_ROUTE24,            REGION_I },
    { MAP_GROUP_ROUTE25,            MAP_NUM_ROUTE25,            REGION_I },
    { MAP_GROUP_CERULEANCAPE,       MAP_NUM_CERULEANCAPE,       REGION_I },

    { MAP_GROUP_SAFFRONCITY,        MAP_NUM_SAFFRONCITY,        REGION_I },
    { MAP_GROUP_ROUTE5,             MAP_NUM_ROUTE5,             REGION_I },
    { MAP_GROUP_ROUTE8,             MAP_NUM_ROUTE8,             REGION_I },

    { MAP_GROUP_CELADONCITY,        MAP_NUM_CELADONCITY,        REGION_I },
    { MAP_GROUP_ROUTE7,             MAP_NUM_ROUTE7,             REGION_I },

    { MAP_GROUP_LAVENDERTOWN,       MAP_NUM_LAVENDERTOWN,       REGION_I },
    { MAP_GROUP_ROUTE10,            MAP_NUM_ROUTE10,            REGION_I },

    { MAP_GROUP_ROUTE9,             MAP_NUM_ROUTE9,             REGION_I },
    { MAP_GROUP_POWERPLANT_EXT,     MAP_NUM_POWERPLANT_EXT,     REGION_I },
    { MAP_GROUP_ROCKTUNNEL_EXT,     MAP_NUM_ROCKTUNNEL_EXT,     REGION_I },

    { MAP_GROUP_ROUTE22,            MAP_NUM_ROUTE22,            REGION_I },
    { MAP_GROUP_ROUTE23,            MAP_NUM_ROUTE23,            REGION_I },
    { MAP_GROUP_INDIGOPLATEAU_EXT,  MAP_NUM_INDIGOPLATEAU_EXT,  REGION_I },

    { MAP_GROUP_POKEMONTOWER,       MAP_NUM_POKEMONTOWER,       REGION_I },

    // ============================================================
    // =================== SEVII ISLANDS 1–3 (REGION_S) ===========
    // ============================================================

    { MAP_GROUP_ONEISLAND,          MAP_NUM_ONEISLAND,          REGION_S },
    { MAP_GROUP_KINDLEROAD,         MAP_NUM_KINDLEROAD,         REGION_S },
    { MAP_GROUP_TREASUREBEACH,      MAP_NUM_TREASUREBEACH,      REGION_S },

    { MAP_GROUP_MTEMBER_EXT,        MAP_NUM_MTEMBER_EXT,        REGION_S },

    { MAP_GROUP_TWOISLAND,          MAP_NUM_TWOISLAND,          REGION_S },
    { MAP_GROUP_CAPEBRINK,          MAP_NUM_CAPEBRINK,          REGION_S },

    { MAP_GROUP_THREEISLAND,        MAP_NUM_THREEISLAND,        REGION_S },
    { MAP_GROUP_BONDBRIDGE,         MAP_NUM_BONDBRIDGE,         REGION_S },
    { MAP_GROUP_BERRYFOREST,        MAP_NUM_BERRYFOREST,        REGION_S },

    { MAP_GROUP_WATERLABYRINTH,     MAP_NUM_WATERLABYRINTH,     REGION_S },
    { MAP_GROUP_RESORTGORGEOUS,     MAP_NUM_RESORTGORGEOUS,     REGION_S },

    { MAP_GROUP_BIRTHISLAND_EXT,    MAP_NUM_BIRTHISLAND_EXT,    REGION_S },
    { MAP_GROUP_BIRTHISLAND_HARBOR, MAP_NUM_BIRTHISLAND_HARBOR, REGION_S },

    // ============================================================
    // =================== SEVII ISLANDS 4–7 (REGION_V) ===========
    // ============================================================

    { MAP_GROUP_FOURISLAND,         MAP_NUM_FOURISLAND,         REGION_V },
    { MAP_GROUP_ICEFALLCAVE_EXT,    MAP_NUM_ICEFALLCAVE_EXT,    REGION_V },

    { MAP_GROUP_FIVEISLAND,         MAP_NUM_FIVEISLAND,         REGION_V },
    { MAP_GROUP_MEMORIALPILLAR,     MAP_NUM_MEMORIALPILLAR,     REGION_V },
    { MAP_GROUP_RESORTAREA,         MAP_NUM_RESORTAREA,         REGION_V },

    { MAP_GROUP_SIXISLAND,          MAP_NUM_SIXISLAND,          REGION_V },
    { MAP_GROUP_PATTERNBUSH,        MAP_NUM_PATTERNBUSH,        REGION_V },
    { MAP_GROUP_RUINVALLEY,         MAP_NUM_RUINVALLEY,         REGION_V },

    { MAP_GROUP_SEVENISLAND,        MAP_NUM_SEVENISLAND,        REGION_V },
    { MAP_GROUP_SEVAULTCANYON,      MAP_NUM_SEVAULTCANYON,      REGION_V },
    { MAP_GROUP_TANOBYRUINS_EXT,    MAP_NUM_TANOBYRUINS_EXT,    REGION_V },

    { MAP_GROUP_TRAINERTOWER_EXT,   MAP_NUM_TRAINERTOWER_EXT,   REGION_V },

    { MAP_GROUP_NAVELROCK_EXT,      MAP_NUM_NAVELROCK_EXT,      REGION_V },
    { MAP_GROUP_NAVELROCK_HARBOR,   MAP_NUM_NAVELROCK_HARBOR,   REGION_V },
    { MAP_GROUP_NAVELROCK_SUMMIT,   MAP_NUM_NAVELROCK_SUMMIT,   REGION_V },

    // ======================= (Next region goes here) =======================
};

#define REGION_DEFAULT REGION_X

static u8 GetRegionFamilyForCurrentMap(void)
{
    u8 group = gSaveBlock1Ptr->location.mapGroup;
    u8 num   = gSaveBlock1Ptr->location.mapNum;

    for (int i = 0; i < ARRAY_COUNT(sRegionFamilyTable); i++)
    {
        if (sRegionFamilyTable[i].mapGroup == group
         && sRegionFamilyTable[i].mapNum   == num)
            return sRegionFamilyTable[i].regionFamily;
    }

    return REGION_DEFAULT;
}


static void UpdateWeatherRollIfNeeded(void)
{
    u8 hour = GetCurrentHour(); // your RTC or playtime hour

    if (hour != gSaveBlock2Ptr->weatherRollHour)
    {
        gSaveBlock2Ptr->weatherRoll = Random() % 1000; // 000–999
        gSaveBlock2Ptr->weatherRollHour = hour;
    }
}

static void GetWeatherDigits(u16 roll, u8 *x, u8 *y, u8 *z)
{
    *x = roll / 100;        // hundreds
    *y = (roll / 10) % 10;  // tens
    *z = roll % 10;         // ones
}

static u8 GetWeatherSlotForRegion(u8 regionFamily)
{
    u8 x, y, z;
    GetWeatherDigits(gSaveBlock2Ptr->weatherRoll, &x, &y, &z);

    switch (regionFamily)
    {
        case REGION_X: return x;                 // hundreds digit
        case REGION_Y: return y;                 // tens digit
        case REGION_Z: return z;                 // ones digit

        case REGION_C: return (x + y) % 10;      // coastal
        case REGION_I: return (x + z) % 10;      // inland
        case REGION_S: return (y + z) % 10;      // sevii
        case REGION_V: return (x + y + z) % 10;  // microclimates
    }

    return 0; // fallback
}

static bool8 IsForcedOutdoorMap(void)
{
    switch (gMapHeader.mapLayoutId)
    {
        case MAP_LAYOUT_ICEPATH_1F:
        case MAP_LAYOUT_ICEPATH_B1F:
        case MAP_LAYOUT_ICEPATH_B2F:
        case MAP_LAYOUT_ICEPATH_B3F:
        case MAP_LAYOUT_BLACKTHORN_GYM:
        case MAP_LAYOUT_CIANWOOD_GYM:
            return TRUE;
    }
    return FALSE;
}

// ---------------------------------------------------------------------------
// Weather ID lookup (map → weather ID)
// ---------------------------------------------------------------------------

// Matches the structure generated by weather_ids.inc
struct MapWeatherIdEntry {
    u8 mapGroup;
    u8 mapNum;
    u8 weatherId;
};

// Auto‑generated from weather_ids.inc
extern const struct MapWeatherIdEntry gMapWeatherIds[];

// Auto‑generated from weather_tables.inc
extern const u8 *const gWeatherTables[];


static u8 GetWeatherIdForCurrentMap(void)
{
    u8 group = gSaveBlock1Ptr->location.mapGroup;
    u8 num   = gSaveBlock1Ptr->location.mapNum;

    for (int i = 0; gMapWeatherIds[i].mapGroup != 0xFF; i++)
    {
        if (gMapWeatherIds[i].mapGroup == group &&
            gMapWeatherIds[i].mapNum   == num)
            return gMapWeatherIds[i].weatherId;
    }

    return 0; // default Z0
}


// ---------------------------------------------------------------------------
// Weather table lookup (weather ID → table → slot)
// ---------------------------------------------------------------------------

static u8 GetWeatherFromTable(u8 weatherId, u8 slot)
{
    const u8 *table = gWeatherTables[weatherId];
    return table[slot];
}


// ---------------------------------------------------------------------------
// Main weather selection logic
// ---------------------------------------------------------------------------

static u8 GetRawWeatherForMap(void)
{
    // Interiors should never use region logic unless explicitly forced
    if (!IsMapTypeOutdoors(gMapHeader.mapType) && !IsForcedOutdoorMap())
        return WEATHER_NONE;

    u8 region = GetRegionFamilyForCurrentMap();
    u8 slot   = GetWeatherSlotForRegion(region);

    u8 weatherId = GetWeatherIdForCurrentMap();
    return GetWeatherFromTable(weatherId, slot);
}


static u8 ApplyTimeOfDayCorrections(u8 weather)
{
    if (IsNightTime())
    {
        if (weather == WEATHER_SUNNY || weather == WEATHER_EXTREME_SUN)
            return WEATHER_NONE; // or WEATHER_CLEAR if you prefer
    }

    return weather;
}

static u8 FinalizeWeather(u8 weather)
{
    if (!IsMapTypeOutdoors(gMapHeader.mapType))
        return WEATHER_NONE;

    if (weather == WEATHER_RAIN)
    {
        // 20–35% chance of thunderstorm
        if (Random() % 100 < 25)
            return WEATHER_RAIN_THUNDERSTORM;
    }


    return weather;
}

u8 DetermineCurrentWeather(void)
{
    UpdateWeatherRollIfNeeded();

    u8 raw = GetRawWeatherForMap();
    u8 corrected = ApplyTimeOfDayCorrections(raw);

    return FinalizeWeather(corrected);
}

// ========================
// END CLIMATE BLOCK 1
// ========================

static u8 TranslateWeatherNum(u8 weather);
static void UpdateRainCounter(u8 newWeather, u8 oldWeather);

void SetSavedWeather(u32 weather)
{
    u8 oldWeather = gSaveBlock1Ptr->weather;
    gSaveBlock1Ptr->weather = TranslateWeatherNum(weather);
    UpdateRainCounter(gSaveBlock1Ptr->weather, oldWeather);
}

u8 GetSav1Weather(void)
{
    return gSaveBlock1Ptr->weather;
}

// CLIMATE BLOCK 2
void SetSavedWeatherFromCurrMapHeader(void)
{
    u8 oldWeather = gSaveBlock1Ptr->weather;
    gSaveBlock1Ptr->weather = DetermineCurrentWeather();
    UpdateRainCounter(gSaveBlock1Ptr->weather, oldWeather);
}
// CLIMATE BLOCK 2

void SetWeather(u32 weather)
{
    SetSavedWeather(weather);
    SetNextWeather(GetSav1Weather());
}

void SetWeather_Unused(u32 weather)
{
    SetSavedWeather(weather);
    SetCurrentAndNextWeather(GetSav1Weather());
}

void DoCurrentWeather(void)
{
    u8 weather = GetSav1Weather();

    SetNextWeather(weather);
}

void ResumePausedWeather(void)
{
    u8 weather = GetSav1Weather();

    SetCurrentAndNextWeather(weather);
}

static const u8 sWeatherCycleRoute119[] = {
    WEATHER_SUNNY,
    WEATHER_RAIN,
    WEATHER_RAIN_THUNDERSTORM,
    WEATHER_RAIN,
};

static const u8 sWeatherCycleRoute123[] = {
    WEATHER_SUNNY,
    WEATHER_SUNNY,
    WEATHER_RAIN,
    WEATHER_SUNNY,
};

static u8 TranslateWeatherNum(u8 weather)
{
    switch (weather)
    {
    case WEATHER_NONE:               return WEATHER_NONE;
    case WEATHER_SUNNY_CLOUDS:       return WEATHER_SUNNY_CLOUDS;
    case WEATHER_SUNNY:              return WEATHER_SUNNY;
    case WEATHER_RAIN:               return WEATHER_RAIN;
    case WEATHER_SNOW:               return WEATHER_SNOW;
    case WEATHER_RAIN_THUNDERSTORM:  return WEATHER_RAIN_THUNDERSTORM;
    case WEATHER_FOG_HORIZONTAL:     return WEATHER_FOG_HORIZONTAL;
    case WEATHER_VOLCANIC_ASH:       return WEATHER_VOLCANIC_ASH;
    case WEATHER_SANDSTORM:          return WEATHER_SANDSTORM;
    case WEATHER_FOG_DIAGONAL:       return WEATHER_FOG_DIAGONAL;
    case WEATHER_UNDERWATER:         return WEATHER_UNDERWATER;
    case WEATHER_SHADE:              return WEATHER_SHADE;
    case WEATHER_DROUGHT:            return WEATHER_DROUGHT;
    case WEATHER_DOWNPOUR:           return WEATHER_DOWNPOUR;
    case WEATHER_UNDERWATER_BUBBLES: return WEATHER_UNDERWATER_BUBBLES;
    case WEATHER_ROUTE119_CYCLE:     return sWeatherCycleRoute119[gSaveBlock1Ptr->weatherCycleStage];
    case WEATHER_ROUTE123_CYCLE:     return sWeatherCycleRoute123[gSaveBlock1Ptr->weatherCycleStage];
    default:                         return WEATHER_NONE;
    }
}

void UpdateWeatherPerDay(u16 increment)
{
    u16 weatherStage = gSaveBlock1Ptr->weatherCycleStage + increment;
    weatherStage %= 4;
    gSaveBlock1Ptr->weatherCycleStage = weatherStage;
}

static void UpdateRainCounter(u8 newWeather, u8 oldWeather)
{
    if (newWeather != oldWeather
        && (newWeather == WEATHER_RAIN || newWeather == WEATHER_RAIN_THUNDERSTORM))
        IncrementGameStat(GAME_STAT_GOT_RAINED_ON);
}

// ============================================================
// END OF VANILLA WEATHER ENGINE
// ============================================================


// ============================================================
// DAY/NIGHT TINT SYSTEM STARTS HERE
// ============================================================

static bool8 IsNightTime(void)
{
    u8 hour = GetCurrentHour();
    return (hour >= 18 || hour < 6);
}

static const s8 sDayTint[3]   = { 0, 0, 0 };
static const s8 sNightTint[3] = { -8, -8, +8 };

static void ApplyPaletteTint(const s8 *tint)
{
    ApplyGlobalTintToPalette(tint[0], tint[1], tint[2]);
}

static void ApplyDayNightTint(void)
{
    if (IsNightTime())
        ApplyPaletteTint(sNightTint);
    else
        ApplyPaletteTint(sDayTint);
}

void ApplyDayNightOnMapLoad(void)
{
    ApplyDayNightTint();
}

void ApplyDayNightOnHourChange(void)
{
    ApplyDayNightTint();
    SetSavedWeatherFromCurrMapHeader();
}

// ============================================================
// END DAY/NIGHT TINT SYSTEM
// ============================================================
