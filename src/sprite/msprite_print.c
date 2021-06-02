#include <ultra64.h>
#include <PR/gs2dex.h>
#include "msprite.h"
#include "src/game/game_init.h"

#include "textures/cream.h"

MSPRITE cream_msprites[] = {
    {cream_tex_0, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_1, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_2, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_3, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_4, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_5, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_6, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_7, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_8, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_9, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_10, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_11, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_12, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_13, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_14, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_15, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_16, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_17, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_18, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_19, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_20, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_21, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_22, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_23, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_24, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_25, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_26, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_27, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_28, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_29, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_30, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_31, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_32, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_33, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_34, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_35, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_36, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_37, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_38, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_39, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_40, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_41, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_42, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_43, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_44, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_45, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_46, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_47, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_48, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_49, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_50, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_51, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_52, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_53, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_54, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_55, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_56, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_57, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_58, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_59, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_60, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_61, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_62, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_63, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_64, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_65, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_66, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_67, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_68, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_69, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_70, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_71, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_72, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_73, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_74, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_75, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_76, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_77, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_78, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_79, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_80, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_81, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_82, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_83, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_84, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_85, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_86, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_87, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_88, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_89, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_90, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_91, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_92, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_93, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_94, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_95, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_96, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_97, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_98, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_99, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_100, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_101, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_102, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_103, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_104, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_105, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_106, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_107, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_108, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_109, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_110, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_111, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_112, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_113, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_114, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_115, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_116, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_117, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_118, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_119, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_120, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_121, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_122, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_123, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_124, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_125, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_126, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
    {cream_tex_127, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64},
};

s16 strlength(char *s) {
  s16 y = 0;
  do {y++;} while (*(++s) != '\0');
  return y;
}

void print_cream(s16 x, s16 y, s16 limit, char *str) {
    s16 i;
    s16 length = strlength(str);
    s16 xOffset = 0;
    s16 yOffset = 0;
    char *tbl = segmented_to_virtual(cream_kerning_table);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDisplayListHead = msp_filter(gDisplayListHead, 1);
    for (i = 0; i < length && (limit < 0 || i < limit); i++) {
        switch (str[i]) {
            case '\n':
                xOffset = 0;
                yOffset += 64;
                break;
            default:
                gDisplayListHead = msp_draw(gDisplayListHead, &cream_msprites[(int) str[i]], x + xOffset, y + yOffset, 85, 85);
                xOffset += tbl[(int) str[i]] * (1 + (1.0f / 3.0f));
                break;
        }
    }
}