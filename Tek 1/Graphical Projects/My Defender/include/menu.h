/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** menu.h
*/
#ifndef MENU_H_
    #define MENU_H_
    #include "my_defender.h"
    #define PLAY 0
    #define EXIT 1
    #define INFO 2
    #define MUTE 3
    #define BACK 4
    #define POP_TEXTURE 5
    #define POP_MAP 6
    #define NEXT 8
    #define BIOME 9
    #define RUN 10
    #define BAR 11

typedef struct button {
    char *path;
    char *path_pressed;
    sfIntRect rect;
    sfVector2f pos;
    int id;
    TYPE type;
    sfTexture *texture;
    sfTexture *texture_pressed;
    sfSprite *sprite;
} button_t;

typedef struct menu {
    float seconds;
    sfClock *clock;
    sfTime time;
    sfIntRect rect;
    sfSprite *sprite_background;
    sfTexture *texture_background;
    lnk_list_t *buttons;
} menu_t;

#endif
