#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_IMG_WIFI166
#define LV_ATTRIBUTE_IMG_IMG_WIFI166
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_IMG_WIFI166 uint8_t img_wifi166_map[] = {
  0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 
  0x00, 0x6f, 0xf9, 0x00, 
  0x07, 0xff, 0xff, 0xd0, 
  0x2f, 0xe5, 0x5b, 0xf8, 
  0xfd, 0x7f, 0xfd, 0x7f, 
  0xf7, 0xff, 0xff, 0xdf, 
  0x0f, 0xd6, 0x57, 0xf0, 
  0x0a, 0x7f, 0xfd, 0xa0, 
  0x00, 0xfe, 0xbf, 0x00, 
  0x00, 0xeb, 0xeb, 0x00, 
  0x00, 0x1e, 0xb4, 0x00, 
  0x00, 0x0b, 0xe0, 0x00, 
  0x00, 0x02, 0x80, 0x00, 
  0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 
};

const lv_img_dsc_t img_wifi166 = {
  .header.cf = LV_IMG_CF_ALPHA_2BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 16,
  .header.h = 16,
  .data_size = 64,
  .data = img_wifi166_map,
};