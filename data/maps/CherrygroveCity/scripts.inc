CherrygroveCity_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, CherrygroveCity_Dummy
    .byte 0

CherrygroveCity_Dummy:
    end

CherrygroveCity_EventScript_FerrySailor::
        lock
        faceplayer
        msgbox CherrygroveCity_Text_FerryPrompt, MSGBOX_YESNO
        compare VAR_RESULT, YES
        goto_if_eq CherrygroveCity_EventScript_FerryDepart
        release
        end

CherrygroveCity_EventScript_FerryDepart::
        fadescreen FADE_TO_BLACK
        warp MAP_SSANNE_EXTERIOR, 73, 11
        fadescreen FADE_FROM_BLACK
        release
        end

CherrygroveCity_Text_FerryPrompt:
        .string "The ferry to Vermilion is boarding.\nWould you like to depart?$"
