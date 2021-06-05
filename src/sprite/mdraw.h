/******************************************************************************
 *                    mdraw.c: Drawing code by devwizard.                     *
 ******************************************************************************/

#ifndef __MDRAW_H__
#define __MDRAW_H__

#include <ultra64.h>

#ifndef __ASSEMBLER__

/* Printing justification */
#define MPRINT_LJUST    0
#define MPRINT_RJUST    1
#define MPRINT_CJUST    2

typedef unsigned int uint;

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
extern void mfilter(uint filter);

/* Drawing sprite */
extern void msprite(const MSPRITE *msp, int x, int y, uint w, uint h);

/* Printing */
extern void mprint_start(void);
extern void mprint(int x, int y, uint max, uint just, float scale, const char *str);

#endif /* __ASSEMBLER__ */

#endif /* __MDRAW_H__ */
