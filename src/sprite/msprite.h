/******************************************************************************
 *                 msprite.h: Sprite draw code by devwizard.                  *
 ******************************************************************************/

#ifndef __MSPRITE_H__
#define __MSPRITE_H__

#include <ultra64.h>

#ifndef __ASSEMBLER__

/* Sprite info */
typedef struct msprite
{
    const void *timg;           /* pointer to the texture data */
    u32 fmt:4;                  /* texture format number */
    u32 siz:4;                  /* texture size number */
    u32 w:12;                   /* width of the texture */
    u32 h:12;                   /* height of the texture */
}
MSPRITE;

/* Set filtering */
extern Gfx *msp_filter(Gfx *gfx, int filter);

/* Sprite drawing */
extern Gfx *msp_draw(
    Gfx *gfx, const MSPRITE *msprite, int x, int y, int w, int h
);

#endif /* __ASSEMBLER__ */

#endif /* __MSPRITE_H__ */
