/******************************************************************************
 *                    mdraw.c: Drawing code by devwizard.                     *
 ******************************************************************************/

#include <ultra64.h>

#include "mdraw.h"

extern void *segment_to_virtual(const void *);
extern Gfx *video_gfx;

static struct
{
    int filter;
}
mdraw;

void mfilter(int filter)
{
    mdraw.filter = filter;
    gDPSetTextureFilter(video_gfx++, mdraw.filter ? G_TF_BILERP : G_TF_POINT);
}

/******************************************************************************
 *                               Drawing sprite                               *
 ******************************************************************************/

static const u8 msp_size[][2] =
{
    {128, 64},
    { 64, 64},
    { 64, 32},
    { 32, 32},
};

void msprite(const MSPRITE *msp, int x, int y, int w, int h)
{
    int fmt = msp->fmt;
    int siz = msp->siz;
    int tw  = msp->w;
    int th  = msp->h;
    int cw;
    int ch;
    int dsdx;
    int dtdy;
    int ty;
    cw = msp_size[siz][0];
    ch = msp_size[siz][1];
    if (mdraw.filter)
    {
        cw >>= 1;
    }
    dsdx = 0x400*4*tw/w;
    dtdy = 0x400*4*th/h;
    gDPSetTextureImage(video_gfx++, fmt, siz, tw, msp->timg);
    for (ty = 0; ty < th; ty += ch)
    {
        int ult;
        int lrt;
        int yl;
        int yh;
        int t;
        int tx;
        ult = ty;
        lrt = ty + ch;
        if (lrt > th)
        {
            lrt = th;
        }
        yl = y + ult*h/th;
        yh = y + lrt*h/th;
        if (yl > 0x1000 || yh < 0)
        {
            continue;
        }
        t = ult << 5;
        if (yl < 0)
        {
            t -= (yl*dtdy) >> 7;
            yl = 0;
        }
        if (mdraw.filter)
        {
            if (ult > 0)
            {
                ult--;
            }
            if (lrt < th)
            {
                lrt++;
            }
            t -= 16;
        }
        for (tx = 0; tx < tw; tx += cw)
        {
            int uls;
            int lrs;
            int xl;
            int xh;
            int s;
            int line;
            uls = tx;
            lrs = tx + cw;
            if (lrs > tw)
            {
                lrs = tw;
            }
            xl = x + uls*w/tw;
            xh = x + lrs*w/tw;
            if (xl > 0x1000 || xh < 0)
            {
                continue;
            }
            s = uls << 5;
            if (xl < 0)
            {
                s -= (xl*dsdx) >> 7;
                xl = 0;
            }
            if (mdraw.filter)
            {
                if (uls > 0)
                {
                    uls--;
                }
                if (lrs < tw)
                {
                    lrs++;
                }
                s -= 16;
            }
            line = (((lrs-uls) << siz >> 1) + 7) >> 3;
            gDPSetTile(
                video_gfx++, fmt, siz, line, 0, G_TX_LOADTILE, 0,
                G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD
            );
            gDPLoadSync(video_gfx++);
            gDPLoadTile(
                video_gfx++, G_TX_LOADTILE,
                (uls  ) << G_TEXTURE_IMAGE_FRAC,
                (ult  ) << G_TEXTURE_IMAGE_FRAC,
                (lrs-1) << G_TEXTURE_IMAGE_FRAC,
                (lrt-1) << G_TEXTURE_IMAGE_FRAC
            );
            gDPPipeSync(video_gfx++);
            gDPSetTile(
                video_gfx++, fmt, siz, line, 0, G_TX_RENDERTILE, 0,
                G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD
            );
            gDPSetTileSize(
                video_gfx++, G_TX_RENDERTILE,
                (uls  ) << G_TEXTURE_IMAGE_FRAC,
                (ult  ) << G_TEXTURE_IMAGE_FRAC,
                (lrs-1) << G_TEXTURE_IMAGE_FRAC,
                (lrt-1) << G_TEXTURE_IMAGE_FRAC
            );
            gSPTextureRectangle(
                video_gfx++, xl, yl, xh, yh, G_TX_RENDERTILE, s, t, dsdx, dtdy
            );
        }
    }
}

/******************************************************************************
 *                                  Printing                                  *
 ******************************************************************************/

extern const u8 *const texture_mprint[];
extern const u8 mprint_kern[];

static int mprint_w(const u8 *kern, uint max, const char *str)
{
    int w = 0;
    while (max > 0 && *str != 0 && *str != '\n')
    {
        int c = *str;
        str++;
        max--;
        w += kern[c];
    }
    return w;
}

void mprint_start(void)
{
    gDPSetTile(
        video_gfx++, G_IM_FMT_I, G_IM_SIZ_16b,
        0, 0, G_TX_LOADTILE, 0,
        G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD,
        G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD
    );
    gDPSetTile(
        video_gfx++, G_IM_FMT_I, G_IM_SIZ_4b,
        ((64>>1)+7) >> 3, 0, G_TX_RENDERTILE, 0,
        G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD,
        G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD
    );
    gDPSetTileSize(
        video_gfx++, G_TX_RENDERTILE, 0, 0,
        (64-1) << G_TEXTURE_IMAGE_FRAC,
        (64-1) << G_TEXTURE_IMAGE_FRAC
    );
}

void mprint(int x, int y, uint max, uint just, const char *str)
{
#define delta   (0x400*4*64/85)
    const u8 *const *table = segment_to_virtual(texture_mprint);
    const u8 *kern         = segment_to_virtual(mprint_kern);
    int st = mdraw.filter ? -16 : 0;
    int xl = x;
start:
    if (just > 0)
    {
        x -= mprint_w(kern, max, str) / just;
    }
    while (max > 0 && *str != 0)
    {
        int c = *str;
        str++;
        max--;
        if (c == '\n')
        {
            x = xl;
            y += kern['\n'];
            goto start;
        }
        else
        {
            const u8 *timg = table[c];
            if (timg != NULL)
            {
                gDPSetTextureImage(
                    video_gfx++, G_IM_FMT_I, G_IM_SIZ_16b, 1, timg
                );
                gDPLoadSync(video_gfx++);
                gDPLoadBlock(
                    video_gfx++, G_TX_LOADTILE, 0, 0,
                    ((64*64+G_IM_SIZ_4b_INCR) >> G_IM_SIZ_4b_SHIFT)-1,
                    CALC_DXT_4b(64)
                );
                gSPTextureRectangle(
                    video_gfx++, x, y, x+85, y+85,
                    G_TX_RENDERTILE, st, st, delta, delta
                );
                gDPPipeSync(video_gfx++);
            }
            x += kern[c];
        }
    }
#undef delta
}
