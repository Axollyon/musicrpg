/******************************************************************************
 *                 msprite.c: Sprite draw code by devwizard.                  *
 ******************************************************************************/

#include <ultra64.h>

#include "msprite.h"

static const u8 msp_tilesize[][2] =
{
    {128, 64},
    { 64, 64},
    { 64, 32},
    { 32, 32},
};

static struct
{
    int filter;
}
msp;

Gfx *msp_filter(Gfx *gfx, int filter)
{
    msp.filter = filter;
    if (gfx != NULL)
    {
        gDPSetTextureFilter(gfx++, msp.filter ? G_TF_BILERP : G_TF_POINT);
    }
    return gfx;
}

Gfx *msp_draw(Gfx *gfx, const MSPRITE *msprite, int x, int y, int w, int h)
{
    int fmt = msprite->fmt;
    int siz = msprite->siz;
    int tw  = msprite->w;
    int th  = msprite->h;
    int cw;
    int ch;
    int dsdx;
    int dtdy;
    int ty;
    cw = msp_tilesize[siz][0];
    ch = msp_tilesize[siz][1];
    if (msp.filter)
    {
        cw >>= 1;
    }
    dsdx = 0x400*4*tw/w;
    dtdy = 0x400*4*th/h;
    gDPSetTextureImage(gfx++, fmt, siz, tw, msprite->timg);
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
        if (msp.filter)
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
            if (msp.filter)
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
                gfx++, fmt, siz, line, 0, G_TX_LOADTILE, 0,
                G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD
            );
            gDPLoadSync(gfx++);
            gDPLoadTile(
                gfx++, G_TX_LOADTILE,
                (uls  ) << G_TEXTURE_IMAGE_FRAC,
                (ult  ) << G_TEXTURE_IMAGE_FRAC,
                (lrs-1) << G_TEXTURE_IMAGE_FRAC,
                (lrt-1) << G_TEXTURE_IMAGE_FRAC
            );
            gDPPipeSync(gfx++);
            gDPSetTile(
                gfx++, fmt, siz, line, 0, G_TX_RENDERTILE, 0,
                G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD
            );
            gDPSetTileSize(
                gfx++, G_TX_RENDERTILE,
                (uls  ) << G_TEXTURE_IMAGE_FRAC,
                (ult  ) << G_TEXTURE_IMAGE_FRAC,
                (lrs-1) << G_TEXTURE_IMAGE_FRAC,
                (lrt-1) << G_TEXTURE_IMAGE_FRAC
            );
            gSPTextureRectangle(
                gfx++, xl, yl, xh, yh, G_TX_RENDERTILE, s, t, dsdx, dtdy
            );
        }
    }
    return gfx;
}
