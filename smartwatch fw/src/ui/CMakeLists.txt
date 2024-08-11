SET(SOURCES ui_Screen1.c
    ui_Screen2.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    fonts/ui_font_coolvectiva30.c
    fonts/ui_font_coolvetica10.c
    fonts/ui_font_lemonMilkBI40.c)

add_library(ui ${SOURCES})
