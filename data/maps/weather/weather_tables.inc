; ============================================================
; ======================= JOHTO SOUTH =========================
; =======================  Z-SERIES  ==========================
; ============================================================

; ------------------------------------------------------------
; Z0 — New Bark / Route 29
; Highest CLEAR = slot 8 → OVERCAST
; ------------------------------------------------------------
WeatherTable_Z0:
    .byte WEATHER_SUNNY
    .byte WEATHER_SUNNY
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_OVERCAST
    .byte WEATHER_RAIN


; ------------------------------------------------------------
; Z1 — Violet Region
; Highest CLEAR = slot 4 → OVERCAST
; ------------------------------------------------------------
WeatherTable_Z1:
    .byte WEATHER_SUNNY
    .byte WEATHER_SUNNY
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_OVERCAST
    .byte WEATHER_FOG
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN


; ------------------------------------------------------------
; Z2 — Route 32 (Coastal Marsh)
; Highest CLEAR = slot 4 → OVERCAST
; ------------------------------------------------------------
WeatherTable_Z2:
    .byte WEATHER_SUNNY
    .byte WEATHER_SUNNY
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_OVERCAST
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN


; ------------------------------------------------------------
; Z3 — Azalea Region
; Highest CLEAR = slot 4 → OVERCAST
; ------------------------------------------------------------
WeatherTable_Z3:
    .byte WEATHER_SUNNY
    .byte WEATHER_SUNNY
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_OVERCAST
    .byte WEATHER_RAIN
    .byte WEATHER_FOG
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN


; ------------------------------------------------------------
; Z4 — Ilex Forest
; Highest CLEAR = slot 3 → OVERCAST
; ------------------------------------------------------------
WeatherTable_Z4:
    .byte WEATHER_SUNNY
    .byte WEATHER_SUNNY
    .byte WEATHER_CLEAR
    .byte WEATHER_OVERCAST
    .byte WEATHER_FOG
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN
    .byte WEATHER_FOG
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN


; ------------------------------------------------------------
; Z5 — Goldenrod Region
; Highest CLEAR = slot 4 → OVERCAST
; ------------------------------------------------------------
WeatherTable_Z5:
    .byte WEATHER_SUNNY
    .byte WEATHER_SUNNY
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_OVERCAST
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN
    .byte WEATHER_FOG
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN


; ------------------------------------------------------------
; Z6 — National Park / Routes 35–37
; Highest CLEAR = slot 8 → OVERCAST
; ------------------------------------------------------------
WeatherTable_Z6:
    .byte WEATHER_SUNNY
    .byte WEATHER_SUNNY
    .byte WEATHER_SUNNY
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_RAIN
    .byte WEATHER_OVERCAST
    .byte WEATHER_RAIN


; ------------------------------------------------------------
; Z7 — Ruins of Alph Exterior
; Highest CLEAR = slot 6 → OVERCAST
; ------------------------------------------------------------
WeatherTable_Z7:
    .byte WEATHER_SUNNY
    .byte WEATHER_SUNNY
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_FOG
    .byte WEATHER_OVERCAST
    .byte WEATHER_FOG
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN


; ------------------------------------------------------------
; Z8 — Route 46 (Foothills)
; Highest CLEAR = slot 6 → OVERCAST
; ------------------------------------------------------------
WeatherTable_Z8:
    .byte WEATHER_SUNNY
    .byte WEATHER_SUNNY
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_OVERCAST
    .byte WEATHER_SANDSTORM
    .byte WEATHER_SANDSTORM
    .byte WEATHER_RAIN


; ------------------------------------------------------------
; Z9 — Cherrygrove / Route 30
; Highest CLEAR = slot 4 → OVERCAST
; ------------------------------------------------------------
WeatherTable_Z9:
    .byte WEATHER_SUNNY
    .byte WEATHER_SUNNY
    .byte WEATHER_CLEAR
    .byte WEATHER_CLEAR
    .byte WEATHER_OVERCAST
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN
    .byte WEATHER_RAIN
    .byte WEATHER_FOG
    .byte WEATHER_RAIN

; ============================================================
; ======================= JOHTO NORTH =========================
; =======================  Y-SERIES  ==========================
; ============================================================


; ------------------------------------------------------------
; Y0 — Mt. Silver Summit Region
; 2 blizzards, 2 snows, 2 rains, 2 fogs, 1 sandstorm, 1 overcast
; No sun allowed
; ------------------------------------------------------------
WeatherTable_Y0:
    .byte WEATHER_OVERCAST       ; 0
    .byte WEATHER_FOG            ; 1
    .byte WEATHER_FOG            ; 2
    .byte WEATHER_RAIN           ; 3
    .byte WEATHER_RAIN           ; 4
    .byte WEATHER_HAIL           ; 5
    .byte WEATHER_SANDSTORM      ; 6
    .byte WEATHER_HAIL           ; 7
    .byte WEATHER_BLIZZARD       ; 8
    .byte WEATHER_BLIZZARD       ; 9


; ------------------------------------------------------------
; Y1 — Ice Path
; Never sunny, never rain
; 7–9 = Blizzard
; Mostly snow/fog
; ------------------------------------------------------------
WeatherTable_Y1:
    .byte WEATHER_OVERCAST       ; 0
    .byte WEATHER_FOG            ; 1
    .byte WEATHER_HAIL           ; 2
    .byte WEATHER_HAIL           ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_HAIL           ; 5
    .byte WEATHER_FOG            ; 6
    .byte WEATHER_BLIZZARD       ; 7
    .byte WEATHER_BLIZZARD       ; 8
    .byte WEATHER_BLIZZARD       ; 9


; ------------------------------------------------------------
; Y2 — Mahogany Basin (Mahogany Town + Route 44)
; Cold, wet, mixed rain/snow, rarely clear
; ------------------------------------------------------------
WeatherTable_Y2:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_OVERCAST       ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_HAIL           ; 6
    .byte WEATHER_RAIN           ; 7
    .byte WEATHER_HAIL           ; 8
    .byte WEATHER_HAIL           ; 9


; ------------------------------------------------------------
; Y3 — Lake of Rage Storm Belt
; Rare clear, fog allowed
; 8 = Blizzard, 9 = Heavy Rain
; One overcast replaced with snow lower in the chart
; ------------------------------------------------------------
WeatherTable_Y3:
    .byte WEATHER_OVERCAST       ; 0
    .byte WEATHER_FOG            ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_HAIL           ; 3
    .byte WEATHER_FOG            ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_HAIL           ; 6
    .byte WEATHER_RAIN           ; 7
    .byte WEATHER_BLIZZARD       ; 8
    .byte WEATHER_HEAVY_RAIN     ; 9


; ------------------------------------------------------------
; Y4 — Blackthorn Ridge
; Cold mountain climate, mixed precip, rarely clear
; ------------------------------------------------------------
WeatherTable_Y4:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_OVERCAST       ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_HAIL           ; 6
    .byte WEATHER_RAIN           ; 7
    .byte WEATHER_HAIL           ; 8
    .byte WEATHER_HAIL           ; 9


; ------------------------------------------------------------
; Y5 — Route 45 Cliffside
; Cold, windy, sandstorms, snow, fog
; ------------------------------------------------------------
WeatherTable_Y5:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_OVERCAST       ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_HAIL           ; 5
    .byte WEATHER_SANDSTORM      ; 6
    .byte WEATHER_HAIL           ; 7
    .byte WEATHER_SANDSTORM      ; 8
    .byte WEATHER_HAIL           ; 9

; ============================================================
; ======================= JOHTO WEST ==========================
; =======================  X-SERIES  ==========================
; ============================================================


; ------------------------------------------------------------
; X0 — Ecruteak–Route 42 Corridor
; Northern West Johto → rare snow allowed
; ------------------------------------------------------------
WeatherTable_X0:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_RAIN           ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_OVERCAST       ; 6
    .byte WEATHER_HAIL           ; 7   ; rare snow
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_HAIL           ; 9   ; rare heavy snow


; ------------------------------------------------------------
; X1 — Peachwood Town
; Rare snow, 2 rain, 1 fog, 1 sun, mostly clear
; ------------------------------------------------------------
WeatherTable_X1:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_FOG            ; 5
    .byte WEATHER_RAIN           ; 6
    .byte WEATHER_RAIN           ; 7
    .byte WEATHER_CLEAR          ; 8
    .byte WEATHER_HAIL           ; 9   ; rare snow


; ------------------------------------------------------------
; X2 — Western Plains (Routes 38–39)
; Southern → no snow ever
; ------------------------------------------------------------
WeatherTable_X2:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_RAIN           ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_OVERCAST       ; 6
    .byte WEATHER_RAIN           ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_RAIN           ; 9   ; heavy rain


; ------------------------------------------------------------
; X3 — Olivine Coastline (Olivine City + Route 40)
; Coastal, fog + rain heavy, no snow
; ------------------------------------------------------------
WeatherTable_X3:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_RAIN           ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_FOG            ; 6
    .byte WEATHER_RAIN           ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_RAIN           ; 9   ; heavy rain


; ------------------------------------------------------------
; X4 — Whirl Islands Exterior + Route 41 + Cianwood Coast
; Never sunny, slot 9 = Kyogre-tier rain
; ------------------------------------------------------------
WeatherTable_X4:
    .byte WEATHER_OVERCAST       ; 0
    .byte WEATHER_OVERCAST       ; 1
    .byte WEATHER_FOG            ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_RAIN           ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_RAIN           ; 6
    .byte WEATHER_RAIN           ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_HEAVY_RAIN     ; 9   ; Kyogre-tier rain


; ------------------------------------------------------------
; X5 — Cliffside Routes (47–48)
; 1 sandstorm slot, no snow, slot 9 = rain
; ------------------------------------------------------------
WeatherTable_X5:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_SANDSTORM      ; 4   ; your sandstorm slot
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_RAIN           ; 6
    .byte WEATHER_FOG            ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_RAIN           ; 9   ; heavy rain


; ------------------------------------------------------------
; X6 — Route 49
; Southern → no snow, balanced coastal mix, extra fog added
; ------------------------------------------------------------
WeatherTable_X6:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_RAIN           ; 4
    .byte WEATHER_FOG            ; 5   ; replaced rain with fog
    .byte WEATHER_OVERCAST       ; 6
    .byte WEATHER_RAIN           ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_RAIN           ; 9   ; heavy rain


; ------------------------------------------------------------
; X7 — Route 50 + Obsidian City
; Foggy 50% of the time, no snow
; ------------------------------------------------------------
WeatherTable_X7:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_FOG            ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_FOG            ; 5
    .byte WEATHER_RAIN           ; 6
    .byte WEATHER_FOG            ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_FOG            ; 9   ; 50% fog achieved


; ------------------------------------------------------------
; X8 — Bleakrest Cove
; Rare snow at slot 9, cold + foggy coastal zone
; ------------------------------------------------------------
WeatherTable_X8:
    .byte WEATHER_OVERCAST       ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_FOG            ; 2
    .byte WEATHER_OVERCAST       ; 3
    .byte WEATHER_RAIN           ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_FOG            ; 6
    .byte WEATHER_RAIN           ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_HAIL           ; 9   ; rare heavy snow

; ============================================================
; ======================= KANTO COASTAL =======================
; =========================  C-SERIES  =========================
; ============================================================


; ------------------------------------------------------------
; C0 — Viridian → Pallet Corridor
; Slightly inland → more fog
; 2 rain slots (8, 9)
; ------------------------------------------------------------
WeatherTable_C0:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_FOG            ; 5   ; geographic adjustment
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_RAIN           ; 8   ; rain 1
    .byte WEATHER_RAIN           ; 9   ; rain 2


; ------------------------------------------------------------
; C1 — Pallet → Cinnabar Sea Route
; Warm southern sea → more sun
; 3 rain slots (7, 8, 9)
; ------------------------------------------------------------
WeatherTable_C1:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_CLEAR          ; 4
    .byte WEATHER_OVERCAST       ; 5
    .byte WEATHER_RAIN           ; 6   ; swapped with fog
    .byte WEATHER_FOG            ; 7   ; swapped with rain
    .byte WEATHER_RAIN           ; 8   ; rain 2
    .byte WEATHER_RAIN           ; 9   ; rain 3


; ------------------------------------------------------------
; C2 — Fuchsia Coast
; Humid → more overcast
; 3 rain slots (7, 8, 9)
; ------------------------------------------------------------
WeatherTable_C2:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_OVERCAST       ; 4   ; geographic adjustment
    .byte WEATHER_FOG            ; 5
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_RAIN           ; 7   ; rain 1
    .byte WEATHER_RAIN           ; 8   ; rain 2
    .byte WEATHER_RAIN           ; 9   ; rain 3


; ------------------------------------------------------------
; C3 — Eastern Coastline (Routes 13–15)
; Windy cliffs → more fog
; 3 rain slots (7, 8, 9)
; ------------------------------------------------------------
WeatherTable_C3:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_FOG            ; 5   ; geographic adjustment
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_RAIN           ; 7   ; rain 1
    .byte WEATHER_RAIN           ; 8   ; rain 2
    .byte WEATHER_RAIN           ; 9   ; rain 3


; ------------------------------------------------------------
; C4 — Lavender Coast (Route 12)
; River delta → earlier fog, but only 2 rain slots
; Rain only in 8 & 9
; ------------------------------------------------------------
WeatherTable_C4:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_FOG            ; 5
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_RAIN           ; 8   ; rain 1
    .byte WEATHER_RAIN           ; 9   ; rain 2


; ------------------------------------------------------------
; C5 — Vermilion Coast
; Port city → more overcast
; 2 rain slots (8, 9)
; ------------------------------------------------------------
WeatherTable_C5:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_OVERCAST       ; 3   ; geographic adjustment
    .byte WEATHER_CLEAR          ; 4
    .byte WEATHER_FOG            ; 5
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_RAIN           ; 8   ; rain 1
    .byte WEATHER_RAIN           ; 9   ; rain 2


; ------------------------------------------------------------
; C6 — Cycling Road (Routes 16–18)
; Elevated → more clear
; 2 rain slots (8, 9)
; ------------------------------------------------------------
WeatherTable_C6:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_CLEAR          ; 4   ; geographic adjustment
    .byte WEATHER_OVERCAST       ; 5
    .byte WEATHER_FOG            ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_RAIN           ; 8   ; rain 1
    .byte WEATHER_RAIN           ; 9   ; rain 2


; ------------------------------------------------------------
; C7 — Seafoam Exterior
; Between C1 and C2 → intermediate, foggy, rainy
; 3 rain slots (7, 8, 9)
; ------------------------------------------------------------
WeatherTable_C7:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_FOG            ; 3   ; geographic adjustment
    .byte WEATHER_CLEAR          ; 4
    .byte WEATHER_CLEAR          ; 5
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_RAIN           ; 7   ; rain 1
    .byte WEATHER_RAIN           ; 8   ; rain 2
    .byte WEATHER_RAIN           ; 9   ; rain 3


; ------------------------------------------------------------
; C8 — Safari Zone Exterior
; Marshy → more fog, but only 2 rain slots
; Rain only in 8 & 9
; ------------------------------------------------------------
WeatherTable_C8:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_FOG            ; 3   ; geographic adjustment
    .byte WEATHER_CLEAR          ; 4
    .byte WEATHER_CLEAR          ; 5
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_RAIN           ; 8   ; rain 1
    .byte WEATHER_RAIN           ; 9   ; rain 2

; ============================================================
; ===================== KANTO INLAND ==========================
; ============================================================


; ------------------------------------------------------------
; I0 — Pewter Region (Pewter, Route 2, Route 3)
; Dry, stable, rocky → fog at slot 3, overcast at gloom slot 5
; ------------------------------------------------------------
WeatherTable_I0:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_CLEAR          ; 4
    .byte WEATHER_OVERCAST       ; 5   ; gloom slot
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_CLEAR          ; 8
    .byte WEATHER_RAIN           ; 9


; ------------------------------------------------------------
; I1 — Cerulean Region (City, Routes 4, 24, 25, Cape)
; Only inland zone with snow → snow at gloom slot 5
; ------------------------------------------------------------
WeatherTable_I1:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_OVERCAST       ; 3
    .byte WEATHER_FOG            ; 4
    .byte WEATHER_HAIL           ; 5   ; gloom slot (snow)
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_CLEAR          ; 8
    .byte WEATHER_RAIN           ; 9


; ------------------------------------------------------------
; I2 — Saffron Region (City, Routes 5, 8)
; Urban heat island → fog at gloom slot 5
; ------------------------------------------------------------
WeatherTable_I2:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_FOG            ; 5   ; gloom slot
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_CLEAR          ; 8
    .byte WEATHER_RAIN           ; 9


; ------------------------------------------------------------
; I3 — Celadon Region (City, Route 7)
; Greener, hazier → overcast at gloom slot 5, fog at 6
; ------------------------------------------------------------
WeatherTable_I3:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_CLEAR          ; 4
    .byte WEATHER_OVERCAST       ; 5   ; gloom slot
    .byte WEATHER_FOG            ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_CLEAR          ; 8
    .byte WEATHER_RAIN           ; 9


; ------------------------------------------------------------
; I4 — Lavender Region (Town, Route 10)
; Extremely foggy, no sun, only slot 0 clear
; ------------------------------------------------------------
WeatherTable_I4:
    .byte WEATHER_CLEAR          ; 0   ; only clear slot
    .byte WEATHER_FOG            ; 1
    .byte WEATHER_OVERCAST       ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_FOG            ; 5   ; gloom slot
    .byte WEATHER_FOG            ; 6
    .byte WEATHER_OVERCAST       ; 7
    .byte WEATHER_OVERCAST       ; 8
    .byte WEATHER_RAIN           ; 9


; ------------------------------------------------------------
; I5 — Route 9 / Power Plant / Rock Tunnel Exterior
; Windy, rocky → fog at gloom slot 5
; ------------------------------------------------------------
WeatherTable_I5:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_FOG            ; 5   ; gloom slot
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_CLEAR          ; 8
    .byte WEATHER_RAIN           ; 9


; ------------------------------------------------------------
; I6 — Victory Road / Indigo Plateau Exterior
; Higher elevation → overcast at gloom slot 5
; ------------------------------------------------------------
WeatherTable_I6:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_FOG            ; 4
    .byte WEATHER_OVERCAST       ; 5   ; gloom slot
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_CLEAR          ; 8
    .byte WEATHER_RAIN           ; 9


; ------------------------------------------------------------
; I7 — Viridian Forest
; Humid, shaded → extra fog + 2 rain slots
; ------------------------------------------------------------
WeatherTable_I7:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_FOG            ; 3
    .byte WEATHER_OVERCAST       ; 4
    .byte WEATHER_FOG            ; 5   ; gloom slot
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_RAIN           ; 8   ; rain 1
    .byte WEATHER_RAIN           ; 9   ; rain 2


; ------------------------------------------------------------
; I8 — Pokémon Tower
; Fog only when Lavender is fog or rain; none otherwise
; ------------------------------------------------------------
WeatherTable_I8:
    .byte WEATHER_NONE           ; 0   ; Lavender CLEAR
    .byte WEATHER_FOG            ; 1   ; Lavender FOG
    .byte WEATHER_NONE           ; 2   ; Lavender OVERCAST
    .byte WEATHER_FOG            ; 3   ; Lavender FOG
    .byte WEATHER_NONE           ; 4   ; Lavender OVERCAST
    .byte WEATHER_FOG            ; 5   ; Lavender FOG
    .byte WEATHER_FOG            ; 6   ; Lavender FOG
    .byte WEATHER_NONE           ; 7   ; Lavender OVERCAST
    .byte WEATHER_NONE           ; 8   ; Lavender OVERCAST
    .byte WEATHER_FOG            ; 9   ; Lavender RAIN

; ============================================================
; =================== SEVII ISLANDS 1–3 =======================
; ============================================================

; S0 — One Island / Kindle Road / Treasure Beach
; 0–8: sun sun sun, clear clear clear, rain rain rain
WeatherTable_S0:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_SUNNY          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_CLEAR          ; 4
    .byte WEATHER_CLEAR          ; 5
    .byte WEATHER_RAIN           ; 6
    .byte WEATHER_RAIN           ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_SUNNY          ; 9   ; sunny on 9


; S1 — Mt. Ember Exterior
; Tropical, but Groudon-level sun on 9
WeatherTable_S1:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_RAIN           ; 2
    .byte WEATHER_SUNNY          ; 3
    .byte WEATHER_CLEAR          ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_SUNNY          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_EXTREME_SUN    ; 9   ; Groudon-level sunlight


; S2 — Two Island / Cape Brink
; Pattern: (sunny, clear, rain) ×3, sunny on 9
WeatherTable_S2:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_RAIN           ; 2
    .byte WEATHER_SUNNY          ; 3
    .byte WEATHER_CLEAR          ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_SUNNY          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_SUNNY          ; 9


; S3 — Three Island / Bond Bridge / Berry Forest
; Custom: 0 sunny, 4 clear, 8 rain, 6 clear, distribution 4S/3C/3R
WeatherTable_S3:
    .byte WEATHER_SUNNY          ; 0   ; fixed sunny
    .byte WEATHER_RAIN           ; 1
    .byte WEATHER_SUNNY          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_CLEAR          ; 4   ; fixed clear
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_CLEAR          ; 6   ; fixed clear
    .byte WEATHER_SUNNY          ; 7
    .byte WEATHER_RAIN           ; 8   ; fixed rain
    .byte WEATHER_SUNNY          ; 9   ; sunny on 9


; S4 — Water Labyrinth / Resort Gorgeous
; Always sunny, Groudon-level sun on 9
WeatherTable_S4:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_SUNNY          ; 2
    .byte WEATHER_SUNNY          ; 3
    .byte WEATHER_SUNNY          ; 4
    .byte WEATHER_SUNNY          ; 5
    .byte WEATHER_SUNNY          ; 6
    .byte WEATHER_SUNNY          ; 7
    .byte WEATHER_SUNNY          ; 8
    .byte WEATHER_EXTREME_SUN    ; 9   ; Groudon-level sunlight


; S5 — Birth Island (Event Island)
; Tropical baseline, sunny on 9
WeatherTable_S5:
    .byte WEATHER_CLEAR          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_RAIN           ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_SUNNY          ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_SUNNY          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_SUNNY          ; 9

; ============================================================
; =================== SEVII ISLANDS 4–7 =======================
; ============================================================

; -------------------------
; V0 — Four Island / Icefall Cave Exterior
; Cold‑edge tropics with 2 fog slots
; -------------------------
WeatherTable_V0:
    .byte WEATHER_RAIN           ; 0
    .byte WEATHER_FOG            ; 1   ; replaced SUNNY → FOG
    .byte WEATHER_CLEAR          ; 2
    .byte WEATHER_RAIN           ; 3
    .byte WEATHER_SUNNY          ; 4
    .byte WEATHER_FOG            ; 5   ; replaced CLEAR → FOG
    .byte WEATHER_RAIN           ; 6
    .byte WEATHER_SUNNY          ; 7
    .byte WEATHER_CLEAR          ; 8
    .byte WEATHER_SUNNY          ; 9   ; required sunny


; -------------------------
; V1 — Five Island / Memorial Pillar / Resort Area
; Storm‑leaning tropics
; -------------------------
WeatherTable_V1:
    .byte WEATHER_RAIN           ; 0
    .byte WEATHER_RAIN           ; 1
    .byte WEATHER_SUNNY          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_RAIN           ; 4
    .byte WEATHER_SUNNY          ; 5
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_SUNNY          ; 7
    .byte WEATHER_CLEAR          ; 8
    .byte WEATHER_SUNNY          ; 9


; -------------------------
; V2 — Six Island / Pattern Bush / Ruin Valley
; Humid tropics with 1 fog slot
; -------------------------
WeatherTable_V2:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_RAIN           ; 2
    .byte WEATHER_SUNNY          ; 3
    .byte WEATHER_RAIN           ; 4
    .byte WEATHER_FOG            ; 5   ; replaced CLEAR → FOG
    .byte WEATHER_RAIN           ; 6
    .byte WEATHER_SUNNY          ; 7
    .byte WEATHER_CLEAR          ; 8
    .byte WEATHER_SUNNY          ; 9


; -------------------------
; V3 — Seven Island / Sevault Canyon / Tanoby Ruins Exterior
; Dry tropics (sun‑heavy)
; -------------------------
WeatherTable_V3:
    .byte WEATHER_SUNNY          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_SUNNY          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_SUNNY          ; 4
    .byte WEATHER_RAIN           ; 5
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_SUNNY          ; 7
    .byte WEATHER_RAIN           ; 8
    .byte WEATHER_SUNNY          ; 9


; -------------------------
; V4 — Trainer Tower Exterior
; Neutral, stable, competitive weather
; -------------------------
WeatherTable_V4:
    .byte WEATHER_CLEAR          ; 0
    .byte WEATHER_CLEAR          ; 1
    .byte WEATHER_SUNNY          ; 2
    .byte WEATHER_CLEAR          ; 3
    .byte WEATHER_SUNNY          ; 4
    .byte WEATHER_CLEAR          ; 5
    .byte WEATHER_SUNNY          ; 6
    .byte WEATHER_CLEAR          ; 7
    .byte WEATHER_SUNNY          ; 8
    .byte WEATHER_SUNNY          ; 9


; -------------------------
; V5 — Navel Rock (Event Island)
; Mythic calm + divine sunlight, with 1 fog slot
; -------------------------
WeatherTable_V5:
    .byte WEATHER_CLEAR          ; 0
    .byte WEATHER_SUNNY          ; 1
    .byte WEATHER_FOG            ; 2   ; replaced CLEAR → FOG
    .byte WEATHER_SUNNY          ; 3
    .byte WEATHER_CLEAR          ; 4
    .byte WEATHER_SUNNY          ; 5
    .byte WEATHER_CLEAR          ; 6
    .byte WEATHER_SUNNY          ; 7
    .byte WEATHER_CLEAR          ; 8
    .byte WEATHER_EXTREME_SUN    ; 9   ; mythic sunlight
