#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <ultra64.h>

#ifndef __ASSEMBLER__

typedef struct sprite
{
    const void *timg;
    u32 fmt:4;
    u32 siz:4;
    u32 w:12;
    u32 h:12;
}
SPRITE;

extern Gfx *sprite_filter(Gfx *gfx, int filter);
extern Gfx *sprite_draw(Gfx *gfx, const SPRITE *sp, int x, int y, int w, int h);

#endif /* __ASSEMBLER__ */

#endif /* __SPRITE_H__ */
