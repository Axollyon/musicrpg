/******************************************************************************
 *                    mdraw.c: Drawing code by devwizard.                     *
 ******************************************************************************/

#ifndef __MDRAW_H__
#define __MDRAW_H__

#include <ultra64.h>

#ifndef __ASSEMBLER__

/* MSprite texture info */
typedef struct msprite
{
    const void *timg;           /* pointer to the texture data */
    u32 fmt:4;                  /* texture format number */
    u32 siz:4;                  /* texture size number */
    u32 w:12;                   /* width of the texture */
    u32 h:12;                   /* height of the texture */
}
MSPRITE;

/* Filtering */
extern void mfilter(int filter);

/* Drawing sprite */
extern void msprite(const MSPRITE *msp, int x, int y, int w, int h);

/* Printing */
extern void mprint_start(void);
extern void mprint(int x, int y, unsigned int max, const char *str);

#endif /* __ASSEMBLER__ */

#endif /* __MDRAW_H__ */
