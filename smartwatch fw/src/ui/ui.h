// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.6
// Project name: idk

#ifndef _IDK_UI_H
#define _IDK_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_uiclock;
extern lv_obj_t * ui_distanceLabel;
extern lv_obj_t * ui_bpmLabel;
extern lv_obj_t * ui_spoLabel;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Label4;
extern lv_obj_t * ui_Chart1;
extern lv_obj_t * ui_batteryBar;
extern lv_obj_t * ui_wifiIndicator;
// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
extern lv_obj_t * ui_Screen2;
extern lv_obj_t * ui_Label5;
extern lv_obj_t * ui_Spinner1;
extern lv_obj_t * ui____initial_actions0;





LV_FONT_DECLARE(ui_font_coolvectiva30);
LV_FONT_DECLARE(ui_font_coolvetica10);
LV_FONT_DECLARE(ui_font_lemonMilkBI40);



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
