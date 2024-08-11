#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 240, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // bg
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.bg = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bg);
            lv_img_set_zoom(obj, 275);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_spinner_create(parent_obj, 1000, 60);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 240, 240);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj0 = obj;
                    lv_obj_set_pos(obj, 59, 66);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &ui_font_theled38, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 112, 58);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_wifi166);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    apply_style_inactive(obj);
                    lv_obj_set_style_img_recolor(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_img_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 120, 168);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_breeze_sans14, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // heart
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.heart = obj;
                    lv_obj_set_pos(obj, 87, 164);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_heart);
                    lv_img_set_zoom(obj, 100);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 120, 200);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_breeze_sans14, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 88, 196);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_location);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_img_recolor(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_img_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
    {
        const char *new_val = evalTextProperty(flowState, 3, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj0);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj0;
            lv_label_set_text(objects.obj0, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj1;
            lv_label_set_text(objects.obj1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj2;
            lv_label_set_text(objects.obj2, new_val);
            tick_value_change_obj = NULL;
        }
    }
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
