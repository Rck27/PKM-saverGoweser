#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void apply_style_active(lv_obj_t *obj);
extern void apply_style_inactive(lv_obj_t *obj);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/