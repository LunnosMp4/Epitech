/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** menu.h
*/

#ifndef MENU_H
    #define MENU_H
    #include "my_rpg.h"

typedef struct settings_s {
    sfIntRect rect;
    sfTexture *bg_menu;
    sfTexture *tex_btns;
    lnk_list_t *buttons;
    lnk_list_t *texts;
} settings_t;

typedef struct main_s {
    sfIntRect rect;
    sfTexture *bg_menu;
    sfTexture *tex_btns;
    sfTexture *popup;
    sfTexture *bar_player;
    lnk_list_t *buttons;
    lnk_list_t *texts;
} main_t;

typedef struct ingame_s {
    sfIntRect rect;
    sfTexture *bg_menu;
    sfTexture *tex_btns;
    sfTexture *popup;
    lnk_list_t *buttons;
    lnk_list_t *texts;
} ingame_t;

typedef struct menu_s {
    main_t *main;
    settings_t *settings;
    ingame_t *ingame;
} menu_t;

menu_t *create_menu(void);

#endif
