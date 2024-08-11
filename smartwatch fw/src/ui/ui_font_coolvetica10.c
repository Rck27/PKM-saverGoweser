/*******************************************************************************
 * Size: 10 px
 * Bpp: 1
 * Opts: --bpp 1 --size 10 --font C:/Users/Dericc/SquareLine/assets/coolvetica condensed rg.otf -o C:/Users/Dericc/SquareLine/assets\ui_font_coolvetica10.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_COOLVETICA10
#define UI_FONT_COOLVETICA10 1
#endif

#if UI_FONT_COOLVETICA10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfa,

    /* U+0022 "\"" */
    0xf0,

    /* U+0023 "#" */
    0x66, 0xf6, 0xea, 0xa0,

    /* U+0024 "$" */
    0x56, 0x66, 0x6a,

    /* U+0025 "%" */
    0xce, 0xcf, 0x3f, 0x30,

    /* U+0026 "&" */
    0xd2, 0x3b, 0x78,

    /* U+0027 "'" */
    0xc0,

    /* U+0028 "(" */
    0x6a, 0xaa, 0x40,

    /* U+0029 ")" */
    0xa5, 0x56, 0x80,

    /* U+002A "*" */
    0x5e, 0x80,

    /* U+002B "+" */
    0x5d, 0x0,

    /* U+002C "," */
    0xc0,

    /* U+002D "-" */
    0xc0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x56, 0xa8,

    /* U+0030 "0" */
    0xf6, 0xdb, 0x78,

    /* U+0031 "1" */
    0x75, 0x54,

    /* U+0032 "2" */
    0xf4, 0xa9, 0x38,

    /* U+0033 "3" */
    0xf4, 0xa3, 0x78,

    /* U+0034 "4" */
    0x2e, 0xde, 0x48,

    /* U+0035 "5" */
    0xf3, 0x93, 0x78,

    /* U+0036 "6" */
    0xf7, 0xdb, 0x78,

    /* U+0037 "7" */
    0xe4, 0xa4, 0x90,

    /* U+0038 "8" */
    0xf6, 0xab, 0x78,

    /* U+0039 "9" */
    0xf6, 0xf3, 0x78,

    /* U+003A ":" */
    0x88,

    /* U+003B ";" */
    0x8c,

    /* U+003C "<" */
    0x71, 0x80,

    /* U+003D "=" */
    0xe3, 0x80,

    /* U+003E ">" */
    0xc7, 0x0,

    /* U+003F "?" */
    0xf4, 0xb4, 0x10,

    /* U+0040 "@" */
    0xff, 0xff, 0xff, 0xe0,

    /* U+0041 "A" */
    0x66, 0x6a, 0x6a, 0x90,

    /* U+0042 "B" */
    0xf6, 0xeb, 0x78,

    /* U+0043 "C" */
    0xf6, 0xcb, 0x78,

    /* U+0044 "D" */
    0xf6, 0xdb, 0x78,

    /* U+0045 "E" */
    0xf2, 0x69, 0x38,

    /* U+0046 "F" */
    0xf2, 0x69, 0x20,

    /* U+0047 "G" */
    0xf6, 0x7b, 0x78,

    /* U+0048 "H" */
    0xb6, 0xfb, 0x68,

    /* U+0049 "I" */
    0xfe,

    /* U+004A "J" */
    0x24, 0x9b, 0x78,

    /* U+004B "K" */
    0xb7, 0x6b, 0x68,

    /* U+004C "L" */
    0x92, 0x49, 0x38,

    /* U+004D "M" */
    0xde, 0xf7, 0xbe, 0xd6, 0xa0,

    /* U+004E "N" */
    0xb7, 0xff, 0x68,

    /* U+004F "O" */
    0xf6, 0xdb, 0x78,

    /* U+0050 "P" */
    0xf6, 0xf9, 0x20,

    /* U+0051 "Q" */
    0xea, 0xaa, 0xaa, 0x45, 0x70,

    /* U+0052 "R" */
    0xf6, 0xeb, 0x68,

    /* U+0053 "S" */
    0xf6, 0x23, 0x78,

    /* U+0054 "T" */
    0xe9, 0x24, 0x90,

    /* U+0055 "U" */
    0xb6, 0xdb, 0x78,

    /* U+0056 "V" */
    0x9a, 0xa6, 0x66, 0x60,

    /* U+0057 "W" */
    0xad, 0x6f, 0xbd, 0xad, 0x60,

    /* U+0058 "X" */
    0x96, 0x66, 0x66, 0x90,

    /* U+0059 "Y" */
    0xb7, 0x24, 0x90,

    /* U+005A "Z" */
    0xe5, 0x25, 0x38,

    /* U+005B "[" */
    0xea, 0xaa, 0xc0,

    /* U+005C "\\" */
    0xaa, 0x54,

    /* U+005D "]" */
    0xd5, 0x55, 0xc0,

    /* U+005E "^" */
    0x4e, 0x80,

    /* U+005F "_" */
    0xe0,

    /* U+0060 "`" */
    0x80,

    /* U+0061 "a" */
    0xf5, 0xde,

    /* U+0062 "b" */
    0x93, 0xdb, 0x78,

    /* U+0063 "c" */
    0xf6, 0x5e,

    /* U+0064 "d" */
    0x27, 0xdb, 0x78,

    /* U+0065 "e" */
    0xf7, 0xde,

    /* U+0066 "f" */
    0x6b, 0xa4, 0x90,

    /* U+0067 "g" */
    0xf6, 0xdf, 0x78,

    /* U+0068 "h" */
    0x93, 0xdb, 0x68,

    /* U+0069 "i" */
    0xbe,

    /* U+006A "j" */
    0x20, 0x92, 0x4d, 0xe0,

    /* U+006B "k" */
    0x92, 0xed, 0x68,

    /* U+006C "l" */
    0xfe,

    /* U+006D "m" */
    0xfd, 0x6b, 0x5a, 0x80,

    /* U+006E "n" */
    0xf6, 0xda,

    /* U+006F "o" */
    0xf6, 0xde,

    /* U+0070 "p" */
    0xf6, 0xdf, 0x20,

    /* U+0071 "q" */
    0xe5, 0x29, 0x4e, 0x14, 0xe0,

    /* U+0072 "r" */
    0xea, 0x80,

    /* U+0073 "s" */
    0xf5, 0x5e,

    /* U+0074 "t" */
    0x93, 0xcb, 0x78,

    /* U+0075 "u" */
    0xb6, 0xde,

    /* U+0076 "v" */
    0xb6, 0xb4,

    /* U+0077 "w" */
    0xaf, 0x7a, 0xa5, 0x0,

    /* U+0078 "x" */
    0xad, 0x3a,

    /* U+0079 "y" */
    0xb6, 0xdf, 0x78,

    /* U+007A "z" */
    0xe9, 0x4e,

    /* U+007B "{" */
    0x69, 0x28, 0x92, 0x60,

    /* U+007C "|" */
    0xff, 0x80,

    /* U+007D "}" */
    0xc9, 0x22, 0x92, 0xc0,

    /* U+007E "~" */
    0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 19, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 27, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 39, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 3, .adv_w = 63, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 7, .adv_w = 61, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 64, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 14, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 20, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 18, .adv_w = 37, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 21, .adv_w = 37, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 24, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 26, .adv_w = 55, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 28, .adv_w = 23, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 29, .adv_w = 28, .box_w = 2, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 30, .adv_w = 23, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 31, .adv_w = 35, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 33, .adv_w = 59, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 32, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 57, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 57, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 50, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 48, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 57, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 59, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 62, .adv_w = 23, .box_w = 1, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 63, .adv_w = 23, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 64, .adv_w = 55, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 66, .adv_w = 55, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 68, .adv_w = 55, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 70, .adv_w = 56, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 75, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 77, .adv_w = 60, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 59, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 47, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 47, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 60, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 23, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 57, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 59, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 48, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 84, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 63, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 57, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 58, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 131, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 60, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 56, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 59, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 60, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 62, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 59, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 54, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 162, .adv_w = 37, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 165, .adv_w = 35, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 37, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 170, .adv_w = 55, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 172, .adv_w = 40, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 173, .adv_w = 41, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 174, .adv_w = 57, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 176, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 57, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 57, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 44, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 192, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 23, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 27, .box_w = 3, .box_h = 9, .ofs_x = -2, .ofs_y = -2},
    {.bitmap_index = 200, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 23, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 91, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 58, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 57, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 212, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 215, .adv_w = 58, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 220, .adv_w = 44, .box_w = 2, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 56, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 55, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 58, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 55, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 57, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 58, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 240, .adv_w = 49, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 242, .adv_w = 37, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 246, .adv_w = 30, .box_w = 1, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 248, .adv_w = 37, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 252, .adv_w = 55, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 2,
    1, 3, 0, 0, 0, 4, 5, 4,
    6, 7, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 0, 0, 0, 0, 0,
    0, 16, 17, 18, 19, 19, 0, 20,
    21, 0, 0, 0, 22, 23, 0, 0,
    19, 24, 19, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 3, 0, 0, 0,
    0, 0, 34, 35, 36, 0, 35, 37,
    38, 34, 39, 40, 41, 42, 34, 34,
    35, 35, 43, 44, 45, 46, 0, 47,
    47, 48, 49, 50, 3, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 2,
    1, 0, 0, 0, 0, 3, 4, 3,
    5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 0, 0, 0, 0, 0,
    16, 0, 17, 0, 18, 0, 0, 0,
    18, 0, 0, 19, 0, 0, 0, 0,
    18, 0, 18, 0, 20, 21, 22, 23,
    24, 25, 26, 27, 0, 0, 0, 0,
    0, 0, 28, 0, 29, 29, 29, 30,
    31, 0, 0, 32, 0, 0, 33, 33,
    29, 33, 29, 33, 34, 35, 36, 37,
    37, 38, 39, 40, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, -6, 0, -10, 0, 0, 0,
    0, -9, 0, 0, 0, 0, 0, 0,
    -9, 0, -12, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -4, 0, -4, 8,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, -15, 0, -8, -5,
    -5, -13, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 28,
    0, 0, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, -6, 0, -2, -9, 0,
    -2, -5, -2, -3, -3, -2, -1, 0,
    0, -2, -2, -3, -13, -2, -9, -8,
    0, -11, 0, -1, -2, -7, -2, 7,
    0, -2, -2, -2, -9, 0, -2, 0,
    0, -2, -6, 0, -7, 0, -9, -6,
    -8, -2, 0, 0, -11, 0, 0, 0,
    -5, 0, -4, -4, -14, 0, -7, -5,
    -12, -12, -9, -2, 0, -5, 0, 3,
    0, 0, 0, 0, -1, -9, 0, -6,
    0, -4, 0, -7, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -11, -3, -11, -3, 0, 0, 0, 0,
    0, 0, 0, -8, -8, -4, -8, 0,
    -5, -8, 0, -4, -4, -4, -5, -5,
    0, 0, -2, 0, 0, 0, -2, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, 0, 0, 0, 0,
    0, -7, -1, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, 0, 0,
    -3, 0, 0, 0, -5, 0, 0, 0,
    -4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -5, 0, -3, -3, 0, 0, -5, 0,
    0, 0, -1, 0, -4, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, -3, 0, 0, 0, -4, 0,
    -2, 0, -1, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -11, -10, 0, -3, -1, -2,
    -3, -11, -2, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 15,
    0, 0, 0, 0, 0, 0, 0, 0,
    -9, -4, 0, -5, 0, 0, 0, 0,
    -4, 0, 0, 0, 0, 0, 0, -11,
    0, -3, -3, -3, -12, -2, -11, -8,
    0, -12, 0, -2, -2, -7, -3, 0,
    0, -2, -2, -2, -8, 0, -3, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, -4, 0, -4, -3,
    -3, -5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, 0, -1, -4, 0, -3, -1,
    -4, -4, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, -10, -2, -11, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -9, 0, -15, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -3, -7, -4, 0,
    -3, -4, 0, -3, -4, -4, -3, -5,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, -4, -3,
    -2, -6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -5, 0, -10, 0, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, -4,
    0, -3, -4, -3, 0, 0, 0, 0,
    0, 0, 0, -2, -2, -7, -3, 0,
    0, -3, -2, -2, -6, 0, -4, 0,
    -14, -4, 0, -13, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -14,
    0, -4, -4, -3, -14, -4, -12, -8,
    0, -16, 0, -3, -3, 0, -2, 0,
    0, -2, -3, -3, -9, 0, -1, 0,
    0, -2, -15, -2, -11, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -9, 0, -14, -1, -2, 0, -3, -2,
    -4, -4, -2, -3, -3, 0, -2, -2,
    -1, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, -3, -3,
    0, -4, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, -1, -1, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -3, 0, 0, 0, -4, 0, -4, -3,
    -5, -7, -1, 0, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -5, -10, -13, -14, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, -1,
    -11, -4, -16, -3, 0, 0, 0, 0,
    0, 0, 0, -11, -11, -7, -11, -1,
    -8, -12, 0, -8, -8, -8, -8, -8,
    0, 0, -2, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, 0,
    0, -5, -9, -7, -12, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -11, -3, -11, -3, 0, 0, 0, 0,
    0, 0, 0, -6, -7, -4, -7, 0,
    -4, -7, 0, -4, -3, -4, -4, -4,
    0, -4, -8, -5, -7, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -8, -1, -7, -3, 0, 0, 0, 0,
    0, 0, 0, -5, -5, -3, -5, 1,
    -3, -5, 0, -3, 0, 0, -3, -3,
    0, -4, 0, -12, 0, 0, 0, 0,
    -6, 0, 0, 0, 0, 0, 0, -5,
    0, -4, 0, -5, 0, -2, 0, 0,
    0, 0, 0, -3, -5, 0, -4, 0,
    0, -4, -4, -4, -7, 0, -3, 0,
    0, -7, -11, -12, -13, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    -12, -4, -17, -5, 0, 0, 0, 0,
    0, 0, 0, -11, -11, 0, -12, 0,
    -9, -11, 0, -10, -7, -7, -8, -8,
    0, -3, 0, -12, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, -1, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, -5, 0, 0,
    0, -4, 0, -3, -5, 0, -2, 0,
    -4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -8,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, -3,
    0, 0, 0, 0, -3, 0, 0, 0,
    -4, 0, -2, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -10,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    0, 0, 0, 0, -3, -4, 0, -2,
    -4, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -9,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, -5, 0, 0,
    2, 0, -11, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -3, 1, -4, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 24,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 6,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 25,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -11, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, -4, 0, -3, 1,
    0, -4, 0, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 33,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, -6, -11, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, 0, 0, -2, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    -4, -2, -2, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -9,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, -2, 0, 0, -4, -3, 0, 0,
    0, 0, -2, 0, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, -3, 0, 0, -1, 0, 0,
    0, 0, -9, -1, -8, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, -3, 0, -3, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, -3, 0, -9, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, -4, 0, -3, 0,
    0, -3, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 25,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 50,
    .right_class_cnt     = 40,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_coolvetica10 = {
#else
lv_font_t ui_font_coolvetica10 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 10,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_COOLVETICA10*/

