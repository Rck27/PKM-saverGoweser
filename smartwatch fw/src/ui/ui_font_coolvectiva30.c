/*******************************************************************************
 * Size: 35 px
 * Bpp: 1
 * Opts: --bpp 1 --size 35 --font C:/Users/Dericc/SquareLine/assets/coolvetica condensed rg.otf -o C:/Users/Dericc/SquareLine/assets\ui_font_coolvectiva30.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_COOLVECTIVA30
#define UI_FONT_COOLVECTIVA30 1
#endif

#if UI_FONT_COOLVECTIVA30

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0x7f,
    0xf8,

    /* U+0022 "\"" */
    0xef, 0xdf, 0xbf, 0x7e, 0xfd, 0xfb, 0xf7,

    /* U+0023 "#" */
    0x1c, 0xc1, 0x8c, 0x18, 0xc1, 0x8c, 0x18, 0xc1,
    0x8c, 0x18, 0xc7, 0xff, 0x7f, 0xf1, 0x98, 0x39,
    0x83, 0x98, 0x39, 0x83, 0x18, 0xff, 0xef, 0xfe,
    0x31, 0x83, 0x18, 0x31, 0x83, 0x38, 0x33, 0x83,
    0x38, 0x73, 0x0,

    /* U+0024 "$" */
    0xe, 0x1, 0xc0, 0x38, 0x3f, 0xc7, 0xfd, 0xe3,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x3, 0xc0, 0x3e,
    0x3, 0xe0, 0x3f, 0x1, 0xf0, 0x1e, 0x1, 0xe0,
    0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xe3, 0xdf, 0xf3,
    0xfe, 0x1f, 0x1, 0xc0, 0x38, 0x0,

    /* U+0025 "%" */
    0x0, 0x63, 0xc3, 0x33, 0x11, 0x99, 0x8c, 0xcc,
    0x66, 0x63, 0x36, 0x19, 0xb0, 0xcd, 0x86, 0x78,
    0x33, 0xc0, 0xf6, 0x0, 0x20, 0x3, 0x78, 0x1e,
    0x60, 0xb3, 0xd, 0x98, 0x6c, 0xc3, 0x66, 0x33,
    0x31, 0x99, 0x8c, 0xcc, 0xc6, 0x66, 0x1e, 0x30,
    0x0,

    /* U+0026 "&" */
    0x1e, 0xf, 0xc1, 0xc0, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0x0, 0xe0, 0xe, 0x0, 0xfb, 0xbf,
    0x7f, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x77, 0x1c, 0xff, 0x87, 0xc0,

    /* U+0027 "'" */
    0xff, 0xff, 0xff,

    /* U+0028 "(" */
    0xc, 0x71, 0x8e, 0x38, 0xc7, 0x1c, 0x71, 0x8e,
    0x38, 0xe3, 0x8e, 0x38, 0xe3, 0x8e, 0x38, 0xe3,
    0x87, 0x1c, 0x71, 0xc3, 0x8e, 0x18, 0x60, 0xc0,

    /* U+0029 ")" */
    0xc3, 0x86, 0x1c, 0x70, 0xc3, 0x8e, 0x38, 0xe1,
    0xc7, 0x1c, 0x71, 0xc7, 0x1c, 0x71, 0xc7, 0x1c,
    0x63, 0x8e, 0x38, 0xe7, 0x1c, 0x63, 0x8c, 0x0,

    /* U+002A "*" */
    0xc, 0x3, 0x0, 0xc3, 0x33, 0xff, 0xcf, 0xc1,
    0xe0, 0xfc, 0x33, 0x18, 0x60,

    /* U+002B "+" */
    0xe, 0x3, 0x80, 0xe0, 0x38, 0xff, 0xff, 0xf0,
    0xe0, 0x38, 0xe, 0x3, 0x80,

    /* U+002C "," */
    0xff, 0xf6, 0xdb, 0xd0,

    /* U+002D "-" */
    0xff, 0xc0,

    /* U+002E "." */
    0xff, 0xf0,

    /* U+002F "/" */
    0x6, 0x1c, 0x38, 0x70, 0xc1, 0x83, 0xe, 0x1c,
    0x30, 0x60, 0xc3, 0x87, 0xc, 0x18, 0x30, 0xe1,
    0xc3, 0x6, 0xc, 0x38, 0x0,

    /* U+0030 "0" */
    0x1f, 0x7, 0xf1, 0xc7, 0x30, 0xee, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xb0, 0xe7, 0x1c, 0x7f, 0x7, 0xc0,

    /* U+0031 "1" */
    0x1c, 0x7f, 0xff, 0x1c, 0x71, 0xc7, 0x1c, 0x71,
    0xc7, 0x1c, 0x71, 0xc7, 0x1c, 0x71, 0xc7, 0x1c,
    0x71, 0xc0,

    /* U+0032 "2" */
    0x3f, 0x8f, 0xfb, 0xc7, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x38, 0x7, 0x1, 0xe0, 0x3c, 0x1f, 0x7,
    0xc1, 0xf0, 0x7c, 0x1f, 0x3, 0xc0, 0xf0, 0x1c,
    0x3, 0x80, 0x70, 0xe, 0x1, 0xff, 0xff, 0xf8,

    /* U+0033 "3" */
    0x1f, 0xf, 0xf9, 0xc7, 0x70, 0x7e, 0xf, 0xc1,
    0xc0, 0x38, 0x7, 0x0, 0xe0, 0x38, 0x3e, 0x7,
    0xe0, 0x1e, 0x1, 0xc0, 0x38, 0x7, 0x0, 0xfc,
    0x1f, 0x83, 0xf0, 0x77, 0x1c, 0xff, 0x87, 0xc0,

    /* U+0034 "4" */
    0x3, 0xc0, 0x78, 0x1f, 0x3, 0xe0, 0xfc, 0x1b,
    0x83, 0x70, 0xee, 0x19, 0xc7, 0x38, 0xc7, 0x38,
    0xe6, 0x1c, 0xc3, 0xb0, 0x77, 0xff, 0xff, 0xe0,
    0x38, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80, 0x70,

    /* U+0035 "5" */
    0xff, 0xdf, 0xfb, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0x0, 0xef, 0x9f, 0xfb, 0xc7, 0x80,
    0x70, 0xe, 0x1, 0xc0, 0x38, 0x7, 0x0, 0xfc,
    0x1f, 0x83, 0xf0, 0x77, 0x1c, 0xff, 0x87, 0xc0,

    /* U+0036 "6" */
    0x1f, 0xf, 0xf9, 0xc7, 0xf0, 0x7e, 0xf, 0xc0,
    0x38, 0x7, 0x0, 0xef, 0x9f, 0xfb, 0xc7, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x77, 0x1c, 0xff, 0x87, 0xc0,

    /* U+0037 "7" */
    0xff, 0xff, 0xc0, 0xe0, 0x60, 0x30, 0x38, 0x1c,
    0xc, 0xe, 0x7, 0x3, 0x81, 0x81, 0xc0, 0xe0,
    0x70, 0x38, 0x1c, 0x1c, 0xe, 0x7, 0x3, 0x81,
    0xc0, 0xe0,

    /* U+0038 "8" */
    0x1f, 0xf, 0xf9, 0xc7, 0x70, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfe, 0x38, 0xfe, 0x3f,
    0xef, 0x1f, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x77, 0x1c, 0xff, 0x87, 0xc0,

    /* U+0039 "9" */
    0x1f, 0xf, 0xf9, 0xc7, 0x70, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf8,
    0xf7, 0xfe, 0x7d, 0xc0, 0x38, 0x7, 0x0, 0xfc,
    0x1f, 0x83, 0xf0, 0x7f, 0x1c, 0xff, 0x87, 0xc0,

    /* U+003A ":" */
    0xff, 0xf0, 0x0, 0x0, 0x1, 0xff, 0xe0,

    /* U+003B ";" */
    0xff, 0xf0, 0x0, 0x0, 0x1, 0xff, 0xed, 0xb7,
    0xa0,

    /* U+003C "<" */
    0x0, 0x40, 0x70, 0x7c, 0x7c, 0x7c, 0x3c, 0xe,
    0x3, 0xe0, 0x3e, 0x3, 0xe0, 0x3c, 0x3, 0x0,
    0x0,

    /* U+003D "=" */
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xc0,

    /* U+003E ">" */
    0x80, 0x38, 0xf, 0x80, 0xf8, 0xf, 0x80, 0xf0,
    0x1c, 0x1f, 0x1f, 0x1f, 0xf, 0x3, 0x0, 0x0,
    0x0,

    /* U+003F "?" */
    0x3f, 0x8f, 0xfb, 0xc7, 0xf0, 0x7e, 0xf, 0xc1,
    0xc0, 0x38, 0x7, 0x1, 0xe0, 0x78, 0xe, 0x3,
    0xc0, 0xf0, 0x1c, 0x3, 0x80, 0x70, 0x0, 0x0,
    0x0, 0x0, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80,

    /* U+0040 "@" */
    0xf, 0xe0, 0xff, 0xc7, 0x3, 0x98, 0x6, 0xc0,
    0xf, 0x0, 0x3c, 0x7e, 0xf3, 0x1b, 0xcc, 0x6f,
    0x31, 0xbc, 0xc6, 0xf3, 0x1b, 0xcc, 0x6f, 0x31,
    0xbc, 0xc6, 0xf3, 0x1b, 0xcc, 0x6f, 0x33, 0xbc,
    0x7f, 0xb0, 0x0, 0xc0, 0x1, 0x80, 0x7, 0x0,
    0xf, 0xfc, 0xf, 0xe0,

    /* U+0041 "A" */
    0xf, 0x80, 0x7c, 0x3, 0xe0, 0x1f, 0x0, 0xf8,
    0xe, 0xe0, 0x77, 0x3, 0xb8, 0x1d, 0xc0, 0xee,
    0x6, 0x70, 0x71, 0xc3, 0x8e, 0x1c, 0x70, 0xe3,
    0x87, 0xfc, 0x3f, 0xe3, 0x83, 0x9c, 0x1c, 0xe0,
    0xe7, 0x7, 0x38, 0x3b, 0xc1, 0xc0,

    /* U+0042 "B" */
    0xff, 0x9f, 0xfb, 0x87, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x3b, 0xfe, 0x7f,
    0xee, 0x1f, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x7e, 0x1f, 0xff, 0xbf, 0xe0,

    /* U+0043 "C" */
    0x1f, 0xf, 0xf9, 0xc7, 0x70, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0x1c, 0x3, 0x80, 0x70,
    0xe, 0x1, 0xc0, 0x38, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x77, 0x1c, 0xff, 0x87, 0xc0,

    /* U+0044 "D" */
    0xff, 0x1f, 0xfb, 0x87, 0x70, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x7e, 0x1d, 0xff, 0xbf, 0xc0,

    /* U+0045 "E" */
    0xff, 0xff, 0xf8, 0x1c, 0xe, 0x7, 0x3, 0x81,
    0xc0, 0xe0, 0x70, 0x3f, 0xdf, 0xee, 0x7, 0x3,
    0x81, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7,
    0xff, 0xfe,

    /* U+0046 "F" */
    0xff, 0xff, 0xf8, 0x1c, 0xe, 0x7, 0x3, 0x81,
    0xc0, 0xe0, 0x70, 0x3f, 0xdf, 0xee, 0x7, 0x3,
    0x81, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7,
    0x3, 0x80,

    /* U+0047 "G" */
    0x1f, 0xf, 0xf9, 0xc7, 0x70, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x0, 0xe0, 0x1c, 0x3, 0x80, 0x73,
    0xfe, 0x7f, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x77, 0x1e, 0xff, 0xc7, 0xd8,

    /* U+0048 "H" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0xff, 0xff,
    0xfe, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1, 0xf8, 0x38,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf8,

    /* U+004A "J" */
    0x0, 0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1,
    0xc0, 0x38, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80,
    0x70, 0xe, 0x1, 0xc0, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x77, 0x1c, 0xff, 0x87, 0xc0,

    /* U+004B "K" */
    0xe0, 0xfc, 0x3f, 0x87, 0x71, 0xee, 0x39, 0xcf,
    0x39, 0xc7, 0x78, 0xee, 0x1f, 0xc3, 0xf8, 0x7f,
    0x8f, 0xf1, 0xee, 0x3d, 0xe7, 0x1c, 0xe3, 0x9c,
    0x7b, 0x87, 0x70, 0xee, 0x1d, 0xc1, 0xf8, 0x38,

    /* U+004C "L" */
    0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7, 0x3, 0x81,
    0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7, 0x3,
    0x81, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7,
    0xff, 0xfe,

    /* U+004D "M" */
    0xf8, 0xf, 0xfc, 0x7, 0xff, 0x3, 0xff, 0x83,
    0xff, 0xc1, 0xff, 0xe0, 0xff, 0xf0, 0x7f, 0xdc,
    0x37, 0xee, 0x3b, 0xf7, 0x1d, 0xfb, 0x8e, 0xfd,
    0xc7, 0x7e, 0x73, 0x3f, 0x3b, 0x9f, 0x9d, 0xcf,
    0xce, 0xe7, 0xe3, 0x63, 0xf1, 0xf1, 0xf8, 0xf8,
    0xfc, 0x7c, 0x7e, 0x3e, 0x3f, 0xe, 0x1f, 0x87,
    0xe,

    /* U+004E "N" */
    0xf8, 0x7f, 0x87, 0xf8, 0x7f, 0x87, 0xfc, 0x7f,
    0xc7, 0xfc, 0x7e, 0xc7, 0xee, 0x7e, 0xe7, 0xe6,
    0x7e, 0x77, 0xe7, 0x7e, 0x77, 0xe3, 0x7e, 0x3f,
    0xe3, 0xfe, 0x1f, 0xe1, 0xfe, 0x1f, 0xe1, 0xfe,
    0xf, 0xe0, 0xf0,

    /* U+004F "O" */
    0x1f, 0xf, 0xf9, 0xc7, 0x70, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x77, 0x1c, 0xff, 0x87, 0xc0,

    /* U+0050 "P" */
    0xff, 0x9f, 0xfb, 0x87, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x87, 0xff,
    0xef, 0xf9, 0xc0, 0x38, 0x7, 0x0, 0xe0, 0x1c,
    0x3, 0x80, 0x70, 0xe, 0x1, 0xc0, 0x38, 0x0,

    /* U+0051 "Q" */
    0x1f, 0x3, 0xfe, 0x1c, 0x71, 0xc1, 0xce, 0xe,
    0x70, 0x73, 0x83, 0x9c, 0x1c, 0xe0, 0xe7, 0x7,
    0x38, 0x39, 0xc1, 0xce, 0xe, 0x70, 0x73, 0x83,
    0x9c, 0x1c, 0xe0, 0xe7, 0x7, 0x38, 0x39, 0xe3,
    0xcf, 0xfe, 0x3f, 0xe0, 0xfe, 0x1, 0xc0, 0xe,
    0x38, 0x71, 0xc3, 0x8e, 0x1c, 0x70, 0xe3, 0x83,
    0xf8, 0xf, 0x80,

    /* U+0052 "R" */
    0xff, 0x9f, 0xfb, 0x87, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x87, 0x7f,
    0xcf, 0xfd, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1, 0xf8, 0x38,

    /* U+0053 "S" */
    0x1f, 0xf, 0xf9, 0xc7, 0x70, 0x7e, 0xf, 0xc1,
    0xf8, 0x7, 0x80, 0xf8, 0xf, 0xc0, 0xfc, 0xf,
    0xc0, 0xfc, 0x7, 0xc0, 0x78, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x7f, 0x1c, 0xff, 0x87, 0xc0,

    /* U+0054 "T" */
    0xff, 0xff, 0xfc, 0x38, 0x7, 0x0, 0xe0, 0x1c,
    0x3, 0x80, 0x70, 0xe, 0x1, 0xc0, 0x38, 0x7,
    0x0, 0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1,
    0xc0, 0x38, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80,

    /* U+0055 "U" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x77, 0x1c, 0xff, 0x87, 0xc0,

    /* U+0056 "V" */
    0x70, 0x73, 0x83, 0x9c, 0x1c, 0xe0, 0xe7, 0x7,
    0x38, 0x38, 0xe3, 0x87, 0x1c, 0x38, 0xe1, 0xc7,
    0xe, 0x38, 0x71, 0xc1, 0xcc, 0xe, 0xe0, 0x77,
    0x3, 0xb8, 0x1d, 0xc0, 0xee, 0x3, 0xe0, 0x1f,
    0x0, 0xf8, 0x7, 0xc0, 0x3e, 0x0,

    /* U+0057 "W" */
    0xf0, 0xe0, 0xee, 0x1e, 0x19, 0xc7, 0xc7, 0x38,
    0xf8, 0xe7, 0x1f, 0x1c, 0xe3, 0x63, 0x9c, 0x6c,
    0x73, 0x8d, 0x8e, 0x71, 0xb1, 0xc7, 0x37, 0x38,
    0xee, 0xee, 0x1d, 0xdd, 0xc3, 0xb9, 0xb8, 0x76,
    0x37, 0xe, 0xc6, 0xe1, 0xd8, 0xdc, 0x3b, 0x1b,
    0x83, 0xe3, 0xf0, 0x7c, 0x7c, 0xf, 0x8f, 0x81,
    0xe0, 0xf0, 0x3c, 0x1e, 0x7, 0x83, 0xc0,

    /* U+0058 "X" */
    0x70, 0x3b, 0x83, 0x9e, 0x1c, 0x70, 0xe3, 0x8e,
    0xe, 0x70, 0x73, 0x83, 0xf8, 0xf, 0xc0, 0x7c,
    0x1, 0xe0, 0xf, 0x0, 0xf8, 0x7, 0xe0, 0x3f,
    0x3, 0xb8, 0x1c, 0xe0, 0xe7, 0xe, 0x3c, 0x70,
    0xe7, 0x7, 0x38, 0x3d, 0xc0, 0xe0,

    /* U+0059 "Y" */
    0x70, 0x77, 0x7, 0x70, 0x73, 0x8e, 0x38, 0xe3,
    0x8e, 0x1d, 0xc1, 0xdc, 0x1d, 0xc0, 0xf8, 0xf,
    0x80, 0xf8, 0x7, 0x0, 0x70, 0x7, 0x0, 0x70,
    0x7, 0x0, 0x70, 0x7, 0x0, 0x70, 0x7, 0x0,
    0x70, 0x7, 0x0,

    /* U+005A "Z" */
    0xff, 0xff, 0xf0, 0x1c, 0xe, 0x3, 0x80, 0xe0,
    0x70, 0x1c, 0xf, 0x3, 0x80, 0xe0, 0x78, 0x1c,
    0x7, 0x3, 0x80, 0xe0, 0x38, 0x1c, 0x7, 0x1,
    0xc0, 0xe0, 0x3f, 0xff, 0xfc,

    /* U+005B "[" */
    0xff, 0xfe, 0x38, 0xe3, 0x8e, 0x38, 0xe3, 0x8e,
    0x38, 0xe3, 0x8e, 0x38, 0xe3, 0x8e, 0x38, 0xe3,
    0x8e, 0x38, 0xe3, 0x8e, 0x3f, 0xfc,

    /* U+005C "\\" */
    0xe0, 0xc1, 0x83, 0x7, 0xe, 0xc, 0x18, 0x30,
    0x70, 0xe0, 0xc1, 0x83, 0x7, 0xe, 0x1c, 0x18,
    0x30, 0x70, 0xe1, 0xc1, 0x80,

    /* U+005D "]" */
    0xff, 0xfc, 0x38, 0x70, 0xe1, 0xc3, 0x87, 0xe,
    0x1c, 0x38, 0x70, 0xe1, 0xc3, 0x87, 0xe, 0x1c,
    0x38, 0x70, 0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x3f,
    0xff, 0xe0,

    /* U+005E "^" */
    0x7, 0x0, 0xf0, 0xf, 0x81, 0xf8, 0x19, 0xc3,
    0x9c, 0x30, 0xc7, 0xe, 0x60, 0x60,

    /* U+005F "_" */
    0xff, 0xff, 0xc0,

    /* U+0060 "`" */
    0x0, 0xc3, 0xc3, 0x81, 0x81, 0x81, 0x80,

    /* U+0061 "a" */
    0x3f, 0x8f, 0xfb, 0xc7, 0xf0, 0x7e, 0xe, 0x3,
    0xc3, 0xf9, 0xff, 0x7c, 0xfe, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xfc, 0x7b, 0xff, 0x3c, 0xe0,

    /* U+0062 "b" */
    0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0x7c, 0xff, 0xde, 0x3f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xe3, 0xff, 0xf7,
    0x3c,

    /* U+0063 "c" */
    0x3f, 0x1f, 0xef, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x3, 0x80, 0xe0, 0x38, 0xe, 0x3, 0x87, 0xe1,
    0xf8, 0x7f, 0x3d, 0xfe, 0x3f, 0x0,

    /* U+0064 "d" */
    0x0, 0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1,
    0xc0, 0x39, 0xf7, 0x7f, 0xfe, 0x3f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xe3, 0xdf, 0xf9,
    0xf7,

    /* U+0065 "e" */
    0x1f, 0xf, 0xfb, 0xc7, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0xff, 0xff, 0xfc, 0x3, 0x80, 0x70,
    0x7e, 0xf, 0xc1, 0xfc, 0x73, 0xfe, 0x1f, 0x0,

    /* U+0066 "f" */
    0xf, 0x1f, 0x3c, 0x38, 0x38, 0x38, 0x38, 0xff,
    0xff, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,

    /* U+0067 "g" */
    0x3c, 0xef, 0xff, 0xc7, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc3, 0xfc, 0x7b, 0xff, 0x3e, 0xe0,
    0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1, 0xfc, 0x73,
    0xfe, 0x1f, 0x0,

    /* U+0068 "h" */
    0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x3b, 0xe7, 0xfe, 0xf1, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1, 0xf8, 0x38,

    /* U+0069 "i" */
    0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf8,

    /* U+006A "j" */
    0x0, 0xe0, 0x1c, 0x3, 0x80, 0x70, 0x0, 0x0,
    0x0, 0x38, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80,
    0x70, 0xe, 0x1, 0xc0, 0x38, 0x7, 0x0, 0xe0,
    0x1c, 0x3, 0x80, 0x70, 0xe, 0x1, 0xc0, 0x38,
    0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7f, 0x1c,
    0xff, 0x87, 0xc0,

    /* U+006B "k" */
    0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0x7, 0xe1, 0xdc, 0x7b, 0x9e, 0x73,
    0x8e, 0xf1, 0xfc, 0x3f, 0x87, 0xf8, 0xff, 0x1e,
    0xe3, 0x9e, 0x71, 0xce, 0x3d, 0xc3, 0xb8, 0x77,
    0x7,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff,

    /* U+006D "m" */
    0xef, 0x1e, 0x7f, 0xdf, 0xbc, 0xf9, 0xfc, 0x38,
    0x7e, 0x1c, 0x3f, 0xe, 0x1f, 0x87, 0xf, 0xc3,
    0x87, 0xe1, 0xc3, 0xf0, 0xe1, 0xf8, 0x70, 0xfc,
    0x38, 0x7e, 0x1c, 0x3f, 0xe, 0x1f, 0x87, 0xf,
    0xc3, 0x87, 0xe1, 0xc3, 0x80,

    /* U+006E "n" */
    0xef, 0x9f, 0xfb, 0xc7, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xe0,

    /* U+006F "o" */
    0x1f, 0xf, 0xfb, 0xc7, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xfc, 0x7b, 0xfe, 0x3f, 0x80,

    /* U+0070 "p" */
    0xef, 0x9f, 0xfb, 0xc7, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xfc, 0x7f, 0xfe, 0xef, 0x9c,
    0x3, 0x80, 0x70, 0xe, 0x1, 0xc0, 0x38, 0x7,
    0x0, 0xe0, 0x0,

    /* U+0071 "q" */
    0x3e, 0xe0, 0x1f, 0xf8, 0xf, 0x1e, 0x3, 0x83,
    0x80, 0xe0, 0xe0, 0x38, 0x38, 0xe, 0xe, 0x3,
    0x83, 0x80, 0xe0, 0xe0, 0x38, 0x38, 0xe, 0xe,
    0x3, 0x83, 0x80, 0xe0, 0xe0, 0x38, 0x38, 0xf,
    0x1e, 0x1, 0xff, 0x80, 0x3e, 0xe0, 0x0, 0x38,
    0x0, 0xe, 0x1c, 0x3, 0x87, 0x0, 0xe1, 0xc0,
    0x38, 0x70, 0xf, 0x3c, 0x1, 0xfe, 0x0, 0x3f,
    0x0,

    /* U+0072 "r" */
    0xe7, 0xff, 0xf8, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0,
    0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
    0xe0,

    /* U+0073 "s" */
    0x3f, 0x1f, 0xee, 0x3f, 0x87, 0xe1, 0xfc, 0xf,
    0x81, 0xf8, 0x3f, 0x83, 0xe0, 0x3c, 0x7, 0xe1,
    0xf8, 0x7f, 0x1d, 0xfe, 0x3f, 0x0,

    /* U+0074 "t" */
    0xe0, 0x38, 0xe, 0x3, 0x80, 0xe0, 0x3f, 0xff,
    0xff, 0x80, 0xe0, 0x38, 0xe, 0x3, 0x80, 0xe1,
    0xf8, 0x7e, 0x1f, 0x87, 0xe1, 0xf8, 0x7e, 0x1f,
    0xcf, 0x7f, 0x87, 0xc0,

    /* U+0075 "u" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xfc, 0x7b, 0xff, 0x3e, 0xe0,

    /* U+0076 "v" */
    0xf0, 0x67, 0xe, 0x70, 0xe7, 0xe, 0x70, 0xe3,
    0x8c, 0x39, 0xc3, 0x9c, 0x39, 0xc3, 0x9c, 0x1d,
    0x81, 0xf8, 0x1f, 0x81, 0xf8, 0xf, 0x80, 0xf0,
    0xf, 0x0,

    /* U+0077 "w" */
    0xe1, 0xc3, 0xb0, 0xf1, 0xdc, 0x78, 0xee, 0x3c,
    0x77, 0x3e, 0x33, 0x9b, 0x19, 0xcd, 0x9c, 0xe6,
    0xee, 0x33, 0x77, 0x1d, 0x9b, 0x8f, 0xcd, 0xc7,
    0xc6, 0xc3, 0xe3, 0x61, 0xf1, 0xf0, 0xf8, 0xf8,
    0x3c, 0x3c, 0x1e, 0x1e, 0x0,

    /* U+0078 "x" */
    0x70, 0x77, 0xe, 0x38, 0xe3, 0x9c, 0x1d, 0xc1,
    0xf8, 0xf, 0x80, 0xf0, 0xf, 0x0, 0xf8, 0x1f,
    0x81, 0xfc, 0x19, 0xc3, 0x9e, 0x38, 0xe7, 0xe,
    0x70, 0x70,

    /* U+0079 "y" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xfc, 0x7b, 0xff, 0x3e, 0xe0,
    0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1, 0xfc, 0x73,
    0xfe, 0x1f, 0x0,

    /* U+007A "z" */
    0xff, 0xff, 0xc0, 0xe0, 0xe0, 0x70, 0x70, 0x38,
    0x3c, 0x1c, 0x1e, 0xe, 0x7, 0x7, 0x3, 0x83,
    0x81, 0xff, 0xff, 0x80,

    /* U+007B "{" */
    0x1e, 0x7c, 0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x38,
    0x70, 0xe1, 0xc3, 0x8f, 0x3c, 0x78, 0x78, 0x70,
    0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x38, 0x70, 0xe1,
    0xc3, 0xe3, 0xc0,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xf3, 0xc3, 0x8e, 0x38, 0xe3, 0x8e, 0x38, 0xe3,
    0x8e, 0x38, 0xe1, 0xc7, 0x38, 0xe3, 0x8e, 0x38,
    0xe3, 0x8e, 0x38, 0xe3, 0x8e, 0xf3, 0xc0,

    /* U+007E "~" */
    0x78, 0x7f, 0xf8, 0x78
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 66, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 94, .box_w = 3, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 135, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 16},
    {.bitmap_index = 17, .adv_w = 220, .box_w = 12, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 52, .adv_w = 214, .box_w = 11, .box_h = 27, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 90, .adv_w = 223, .box_w = 13, .box_h = 25, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 131, .adv_w = 202, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 163, .adv_w = 69, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 16},
    {.bitmap_index = 166, .adv_w = 129, .box_w = 6, .box_h = 31, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 190, .adv_w = 129, .box_w = 6, .box_h = 31, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 214, .adv_w = 186, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 14},
    {.bitmap_index = 227, .adv_w = 193, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 240, .adv_w = 80, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -6},
    {.bitmap_index = 244, .adv_w = 99, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 246, .adv_w = 80, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 121, .box_w = 7, .box_h = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 207, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 111, .box_w = 6, .box_h = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 319, .adv_w = 200, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 200, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 383, .adv_w = 204, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 415, .adv_w = 203, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 447, .adv_w = 203, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 479, .adv_w = 169, .box_w = 9, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 505, .adv_w = 199, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 537, .adv_w = 203, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 80, .box_w = 3, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 80, .box_w = 3, .box_h = 23, .ofs_x = 1, .ofs_y = -6},
    {.bitmap_index = 585, .adv_w = 193, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 602, .adv_w = 193, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 614, .adv_w = 193, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 631, .adv_w = 194, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 663, .adv_w = 262, .box_w = 14, .box_h = 25, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 707, .adv_w = 208, .box_w = 13, .box_h = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 745, .adv_w = 204, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 777, .adv_w = 203, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 809, .adv_w = 207, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 841, .adv_w = 164, .box_w = 9, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 867, .adv_w = 163, .box_w = 9, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 893, .adv_w = 203, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 925, .adv_w = 209, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 957, .adv_w = 81, .box_w = 3, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 966, .adv_w = 199, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 998, .adv_w = 206, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1030, .adv_w = 167, .box_w = 9, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1056, .adv_w = 293, .box_w = 17, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1105, .adv_w = 220, .box_w = 12, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1140, .adv_w = 203, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1172, .adv_w = 200, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1204, .adv_w = 202, .box_w = 13, .box_h = 31, .ofs_x = 1, .ofs_y = -8},
    {.bitmap_index = 1255, .adv_w = 203, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1287, .adv_w = 210, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1319, .adv_w = 196, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1351, .adv_w = 206, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1383, .adv_w = 208, .box_w = 13, .box_h = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1421, .adv_w = 305, .box_w = 19, .box_h = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1476, .adv_w = 218, .box_w = 13, .box_h = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1514, .adv_w = 207, .box_w = 12, .box_h = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1549, .adv_w = 189, .box_w = 10, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1578, .adv_w = 129, .box_w = 6, .box_h = 29, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 1600, .adv_w = 121, .box_w = 7, .box_h = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1621, .adv_w = 129, .box_w = 7, .box_h = 29, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 1647, .adv_w = 193, .box_w = 12, .box_h = 9, .ofs_x = 0, .ofs_y = 14},
    {.bitmap_index = 1661, .adv_w = 139, .box_w = 9, .box_h = 2, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1664, .adv_w = 143, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 18},
    {.bitmap_index = 1671, .adv_w = 199, .box_w = 11, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1695, .adv_w = 203, .box_w = 11, .box_h = 24, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1728, .adv_w = 198, .box_w = 10, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1750, .adv_w = 203, .box_w = 11, .box_h = 24, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1783, .adv_w = 201, .box_w = 11, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1807, .adv_w = 156, .box_w = 8, .box_h = 24, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1831, .adv_w = 203, .box_w = 11, .box_h = 25, .ofs_x = 1, .ofs_y = -8},
    {.bitmap_index = 1866, .adv_w = 204, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1898, .adv_w = 81, .box_w = 3, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1907, .adv_w = 94, .box_w = 11, .box_h = 31, .ofs_x = -6, .ofs_y = -8},
    {.bitmap_index = 1950, .adv_w = 202, .box_w = 11, .box_h = 24, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1983, .adv_w = 81, .box_w = 3, .box_h = 24, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1992, .adv_w = 319, .box_w = 17, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2029, .adv_w = 204, .box_w = 11, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2053, .adv_w = 200, .box_w = 11, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2077, .adv_w = 203, .box_w = 11, .box_h = 25, .ofs_x = 1, .ofs_y = -8},
    {.bitmap_index = 2112, .adv_w = 203, .box_w = 18, .box_h = 25, .ofs_x = 1, .ofs_y = -8},
    {.bitmap_index = 2169, .adv_w = 155, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2186, .adv_w = 198, .box_w = 10, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2208, .adv_w = 192, .box_w = 10, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2236, .adv_w = 203, .box_w = 11, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2260, .adv_w = 191, .box_w = 12, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2286, .adv_w = 279, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2323, .adv_w = 200, .box_w = 12, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2349, .adv_w = 203, .box_w = 11, .box_h = 25, .ofs_x = 1, .ofs_y = -8},
    {.bitmap_index = 2384, .adv_w = 172, .box_w = 9, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2404, .adv_w = 129, .box_w = 7, .box_h = 30, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 2431, .adv_w = 105, .box_w = 3, .box_h = 30, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 2443, .adv_w = 129, .box_w = 6, .box_h = 30, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 2466, .adv_w = 193, .box_w = 10, .box_h = 3, .ofs_x = 1, .ofs_y = 10}
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
    0, 0, -22, 0, -34, 0, 0, 0,
    0, -33, 0, 0, 0, 0, 0, 0,
    -31, 0, -42, -1, 0, 0, 0, 0,
    0, 0, 0, -13, -15, 0, -13, 27,
    0, -13, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -8, 0, 0, 0, -52, 0, -26, -18,
    -16, -45, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 99,
    0, 0, 0, 0, 0, 0, 0, 0,
    -22, 0, 0, -22, 0, -7, -31, 0,
    -7, -17, -6, -11, -11, -7, -5, 0,
    0, -7, -7, -9, -45, -7, -30, -29,
    0, -39, 0, -5, -8, -26, -7, 26,
    0, -8, -8, -7, -31, 0, -6, 0,
    0, -8, -22, 0, -24, 0, -32, -21,
    -27, -7, 0, 0, -39, 0, 0, 0,
    -19, 0, -16, -12, -50, 0, -25, -18,
    -40, -40, -32, -6, 0, -16, 0, 10,
    0, -1, 0, 0, -5, -30, 0, -22,
    0, -16, 0, -25, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -39, -9, -40, -10, 0, 0, 0, 0,
    0, 0, 0, -29, -29, -13, -29, 0,
    -18, -29, 0, -13, -13, -12, -17, -18,
    0, 0, -7, 0, 0, 0, -6, 0,
    0, 0, 0, 0, -11, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -21, 0, 0, 0, 0,
    0, -26, -3, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -16, 0, 0, 0,
    -11, 0, 0, 0, -17, 0, 0, 0,
    -15, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -17, 0, -11, -10, 0, 0, -18, 0,
    0, 0, -3, 0, -13, 0, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -11, 0, -11, 0, 0, 0, -14, 0,
    -6, 0, -2, 0, -12, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -8, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -37, -34, 0, -11, -2, -7,
    -11, -40, -6, -8, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -7, 0, 0, 0, 0, 0,
    -3, 0, 0, 0, -11, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -7, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 53,
    0, 0, 0, 0, 0, 0, 0, 0,
    -31, -12, 0, -19, 0, 0, 0, 0,
    -13, 0, 0, 0, 0, 0, 0, -38,
    0, -9, -9, -10, -41, -8, -39, -27,
    0, -40, 0, -6, -8, -23, -10, 0,
    0, -8, -8, -8, -28, 0, -10, 0,
    0, 0, 0, 0, -6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, 0, -15, 0, -13, -9,
    -11, -18, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -7, 0, -10, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -9, 0, 0, -2, -12, 0, -9, -3,
    -15, -16, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -16, -36, -6, -38, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -31, 0, -52, 0, 0, 0, 0, 0,
    0, 0, 0, -12, -11, -25, -12, 0,
    -11, -13, 0, -11, -13, -16, -11, -16,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -17, 0, -13, -10,
    -6, -21, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -16, 0, -36, 0, 0, 0, 0,
    -12, 0, 0, 0, 0, 0, 0, -15,
    0, -12, -13, -11, 0, 0, 0, 0,
    0, 0, 0, -6, -8, -24, -11, 0,
    0, -10, -8, -8, -21, 0, -15, 0,
    -50, -16, 0, -47, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -48,
    0, -12, -13, -10, -50, -13, -44, -27,
    0, -57, 0, -9, -12, 0, -8, 0,
    0, -8, -11, -10, -33, 0, -4, 0,
    0, -8, -54, -6, -38, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -30, 0, -49, -3, -8, 0, -10, -6,
    -15, -15, -8, -10, -9, 0, -7, -6,
    -3, -10, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, 0, -11, -9,
    0, -13, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 0,
    -4, 0, -3, -5, -11, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -7,
    -9, 0, 0, 0, -15, 0, -15, -11,
    -16, -23, -4, 0, 0, -12, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -17, -34, -46, -49, 0, 0, 0,
    -10, 0, 0, 0, 0, 0, 0, -4,
    -39, -12, -57, -10, 0, 0, 0, 0,
    0, 0, 0, -40, -40, -25, -40, -4,
    -27, -42, 0, -27, -30, -30, -30, -30,
    0, 0, -7, 0, -10, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -8, 0, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -6, 0, 0,
    0, -16, -30, -25, -41, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -8,
    -39, -9, -38, -10, 0, 0, 0, 0,
    0, 0, 0, -21, -26, -16, -25, 0,
    -14, -24, 0, -14, -11, -12, -14, -14,
    0, -16, -29, -18, -26, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    -27, -3, -25, -10, 0, 0, 0, 0,
    0, 0, 0, -18, -17, -12, -17, 2,
    -12, -18, 0, -12, 0, 0, -12, -11,
    0, -16, 0, -40, 0, 0, 0, 0,
    -20, 0, 0, 0, 0, 0, 0, -19,
    0, -16, 0, -19, 0, -6, 0, 0,
    0, 0, 0, -11, -18, 0, -15, 0,
    0, -16, -15, -15, -25, 0, -11, 0,
    0, -24, -39, -40, -46, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -15,
    -40, -15, -60, -17, 0, 0, 0, 0,
    0, 0, 0, -40, -39, 0, -40, 0,
    -32, -38, 0, -35, -26, -25, -27, -29,
    0, -10, 0, -44, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    0, -3, -9, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -15, -18, 0, 0,
    0, -12, 0, -11, -17, 0, -6, 0,
    -12, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -28,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -10, 0, -10,
    0, 0, 0, 0, -9, 0, 0, 0,
    -12, 0, -8, 0, -12, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -34,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -9, 0, 0,
    0, 0, 0, 0, -9, -13, 0, -7,
    -13, 0, -8, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -32,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, -16, 0, 0,
    6, 0, -40, -22, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -13, -11, 3, -12, -1,
    0, -8, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 85,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 22,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 88,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -38, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -10, -13, 0, -11, 2,
    0, -15, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 11,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 117,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -40, -20, -38, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -10, 0, 0, -8, 0,
    0, -9, 0, 0, 0, 0, 0, 0,
    -12, -6, -6, 0, -9, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -30,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -5, 0, 0,
    0, -7, 0, 0, -13, -11, 0, 0,
    0, 0, -7, 0, -8, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, 0,
    0, 0, -10, 0, 0, -5, 0, 0,
    0, 0, -31, -5, -29, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -11, -10, 0, -10, 0,
    0, -10, 0, 0, 0, 0, 0, 0,
    0, -10, 0, -32, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -7, -13, 0, -10, 0,
    0, -11, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 86,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -19, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -8, 0, 0, 0,
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
const lv_font_t ui_font_coolvectiva30 = {
#else
lv_font_t ui_font_coolvectiva30 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 34,          /*The maximum line height required by the font*/
    .base_line = 8,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -5,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_COOLVECTIVA30*/
