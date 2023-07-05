/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** create_main.c
*/

#include "my_rpg.h"

static void create_main(menu_t *menu)
{
    menu->main = malloc(sizeof(main_t));
    menu->ingame = malloc(sizeof(ingame_t));
    menu->main->buttons = NULL;
    menu->main->texts = NULL;
    menu->main->bg_menu = TEXTURE("assets/img/gui/BackgroundMenu.jpg", NULL);
    menu->ingame->buttons = NULL;
    menu->ingame->texts = NULL;
}

static void create_settings(menu_t *menu)
{
    menu->settings = malloc(sizeof(settings_t));
    menu->settings->buttons = NULL;
    menu->settings->texts = NULL;
}

static void create_texts(menu_t *menu)
{
    create_text((utils_txt_t) {{WIDTH / 3 + 100, 70}, TEXT,
    75, "My RPG", {255, 255, 255, 255}}, &menu->main->texts);
    create_text((utils_txt_t) {{WIDTH / 3 + 80, 80}, TEXT,
    65, "Settings", {255, 255, 255, 255}}, &menu->settings->texts);
    create_text((utils_txt_t) {{100, WIDTH / 7},
    TEXT, 45, "Volume :", {255, 255, 255, 255}}, &menu->settings->texts);
    create_text((utils_txt_t) {{320, WIDTH / 7},
    NB_VOL, 45, "0 %", {255, 255, 255, 255}}, &menu->settings->texts);
    create_text((utils_txt_t) {{100, WIDTH / 3 - 20},
    TEXT, 45, "Screen Size", {255, 255, 255, 255}}, &menu->settings->texts);
    create_text((utils_txt_t) {{WIDTH / 3 + 100, 70}, TEXT_P,
    75, "Pause", {255, 255, 255, 255}}, &menu->ingame->texts);
}

menu_t *create_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    create_main(menu);
    create_settings(menu);
    create_buttons(menu);
    create_texts(menu);
    return menu;
}
