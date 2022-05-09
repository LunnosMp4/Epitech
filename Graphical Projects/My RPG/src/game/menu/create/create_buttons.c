/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** init_buttons.c
*/

#include "my_rpg.h"

static void create_buttons2(menu_t *menu)
{
    create_object((utils_t) {{2880, 0, 240, 120}, {80, 250},
    BTN_VOL_M}, &menu->settings->buttons, menu->main->tex_btns);
    create_object((utils_t) {{2400, 0, 240, 120}, {380, 250},
    BTN_VOL_P}, &menu->settings->buttons, menu->main->tex_btns);
    create_object((utils_t) {{2880, 0, 240, 120}, {80, 450},
    BTN_SIZE_M}, &menu->settings->buttons, menu->main->tex_btns);
    create_object((utils_t) {{2400, 0, 240, 120}, {380, 450},
    BTN_SIZE_P}, &menu->settings->buttons, menu->main->tex_btns);
    create_object((utils_t) {{0, 0, 480, 240}, {25, 0},
    POPUP}, &menu->settings->buttons, menu->main->popup);
    create_object((utils_t) {{1920, 0, 240, 120}, {80, 400},
    BTN_EXIT}, &menu->ingame->buttons, menu->main->tex_btns);
    create_object((utils_t) {{0, 0, 240, 120}, {80, 120},
    BTN_PLAY}, &menu->ingame->buttons, menu->main->tex_btns);
    create_object((utils_t) {{0, 0, 480, 240}, {825, 20},
    POPUP_P}, &menu->ingame->buttons, menu->main->popup);
    create_object((utils_t) {{0, 0, 600, 338}, {0, -70},
    BG}, &menu->main->buttons, menu->main->bg_menu);
    create_object((utils_t) {{0, 0, 600, 338}, {0, -70},
    BG}, &menu->settings->buttons, menu->main->bg_menu);
}

void create_buttons(menu_t *menu)
{
    menu->main->tex_btns = TEXTURE("assets/img/gui/Buttons.png", NULL);
    menu->main->popup = TEXTURE("assets/img/gui/BackgroundPopUp.png", NULL);

    create_object((utils_t) {{0, 0, 240, 120}, {80, 120},
    BTN_PLAY}, &menu->main->buttons, menu->main->tex_btns);
    create_object((utils_t) {{3360, 0, 240, 120}, {80, 260},
    BTN_SETTINGS}, &menu->main->buttons, menu->main->tex_btns);
    create_object((utils_t) {{1920, 0, 240, 120}, {80, 400},
    BTN_EXIT}, &menu->main->buttons, menu->main->tex_btns);
    create_buttons2(menu);
}
