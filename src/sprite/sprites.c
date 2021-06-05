#include <ultra64.h>
#include "mdraw.h"
#include "game/game_init.h"

// Main menu and credits (can only be used in the "menu" level)

extern const u16 texture_titlebg[];
MSPRITE sprite_titlebg = {texture_titlebg, G_IM_FMT_RGBA, G_IM_SIZ_16b, 480, 360};

void draw_titlebg(void) {
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    mfilter(1);
    msprite(&sprite_titlebg, 0, 0, 1280, 960);
}


extern const u16 texture_axollyon[];
MSPRITE sprite_axollyon = {texture_axollyon, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 128};

extern const u16 texture_devwizard[];
MSPRITE sprite_devwizard = {texture_devwizard, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 128};

extern const u16 texture_qjrocks[];
MSPRITE sprite_qjrocks = {texture_qjrocks, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 128};

void draw_creditspfp(int id, uint x, uint y) {
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    mfilter(1);
    switch (id) {
        case 0:
            msprite(&sprite_axollyon, x, y, 192, 192);
            break;
        case 1:
            msprite(&sprite_devwizard, x, y, 192, 192);
            break;
        case 2:
            msprite(&sprite_qjrocks, x, y, 192, 192);
            break;
    }
}