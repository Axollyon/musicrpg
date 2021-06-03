#include <ultra64.h>
#include "mdraw.h"
#include "game/game_init.h"

extern const u16 texture_titlebg[];
MSPRITE sprite_titlebg = {texture_titlebg, G_IM_FMT_RGBA, G_IM_SIZ_16b, 480, 360};

void draw_titlebg(void) {
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    mfilter(1);
    msprite(&sprite_titlebg, 0, 0, 1280, 960);
}