#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "macros.h"
#include "surface_terrains.h"
#include "types.h"

#ifdef VERSION_EU
#include "text_strings.h"
#endif
#include "make_const_nonconst.h"

#include "levels/menu/titlebg.c"

const Collision main_menu_seg7_collision[] = {
    COL_INIT(),
    COL_VERTEX_INIT(0x4),
    COL_VERTEX( 8192, -1000, -8192),
    COL_VERTEX(-8192, -1000, -8192),
    COL_VERTEX(-8192, -1000,  8192),
    COL_VERTEX( 8192, -1000,  8192),
    COL_TRI_INIT(SURFACE_DEFAULT, 2),
    COL_TRI(0, 1, 2),
    COL_TRI(0, 2, 3),
    COL_TRI_STOP(),
    COL_END(),
};