#include "global.h"
#include "palette.h"

void ApplyFullPaletteStack(void);

void ApplyGlobalTintToPalette(s8 r, s8 g, s8 b)
{
    // Ignore r/g/b — your new tint engine handles all tint layers internally
    ApplyFullPaletteStack();
}
