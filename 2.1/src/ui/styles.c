#include "styles.h"
#include "images.h"
#include "fonts.h"

void apply_style_active(lv_obj_t *obj) {
    lv_obj_set_style_img_recolor(obj, lv_color_hex(0xffff3939), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_inactive(lv_obj_t *obj) {
    apply_style_active(obj);
    lv_obj_set_style_img_recolor(obj, lv_color_hex(0xffff3939), LV_PART_MAIN | LV_STATE_DEFAULT);
};

