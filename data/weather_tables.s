    .section .rodata

    .align 2

    .include "data/weather_tables.inc"

    .global gWeatherTables
gWeatherTables:
    .word WeatherTable_Z0
    .word WeatherTable_Z1
    .word WeatherTable_Z2
    .word WeatherTable_Z3
    .word WeatherTable_Z4
    .word WeatherTable_Z5
    .word WeatherTable_Z6
    .word WeatherTable_Z7
    .word WeatherTable_Z8
    .word WeatherTable_Z9

    .word WeatherTable_Y0
    .word WeatherTable_Y1
    .word WeatherTable_Y2
    .word WeatherTable_Y3
    .word WeatherTable_Y4
    .word WeatherTable_Y5

    .word WeatherTable_X0
    .word WeatherTable_X1
    .word WeatherTable_X2
    .word WeatherTable_X3
    .word WeatherTable_X4
    .word WeatherTable_X5
    .word WeatherTable_X6
    .word WeatherTable_X7
    .word WeatherTable_X8

    .word WeatherTable_C0
    .word WeatherTable_C1
    .word WeatherTable_C2
    .word WeatherTable_C3
    .word WeatherTable_C4
    .word WeatherTable_C5
    .word WeatherTable_C6
    .word WeatherTable_C7
    .word WeatherTable_C8

    .word WeatherTable_I0
    .word WeatherTable_I1
    .word WeatherTable_I2
    .word WeatherTable_I3
    .word WeatherTable_I4
    .word WeatherTable_I5
    .word WeatherTable_I6
    .word WeatherTable_I7
    .word WeatherTable_I8

    .word WeatherTable_S0
    .word WeatherTable_S1
    .word WeatherTable_S2
    .word WeatherTable_S3
    .word WeatherTable_S4
    .word WeatherTable_S5

    .word 0   @ terminator
