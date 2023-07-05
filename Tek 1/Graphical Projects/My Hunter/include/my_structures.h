/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-loic.tisseyre
** File description:
** my_hunter.h
*/

#ifndef MY_HUNTER_H
    #define MY_HUNTER_H

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>

    #define WIDTH 800
    #define HEIGHT 600

typedef struct game {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfColor clear_color;
    sfEvent event;
    sfMusic *gun;
    sfMusic *music;
    sfMusic *GameOver;
    sfMusic *blood;
    sfFont *font;
    sfText *text;
    sfText *textLoose;
    sfText *textS;
    sfText *textL;
    sfText *textGO;
    char *buff;
    char *buff2;
    float seconds;
    float seconds2;
    int speed;
    int score;
    int loose;
} game_t;

typedef struct animation {
    sfIntRect rect;
    sfIntRect rect2;
    sfClock *clock;
    sfClock *clock2;
    sfTime time;
    sfTime time2;
} animation_t;

typedef struct entity {
    sfTexture *texture;
    sfTexture *background;
    sfTexture *texcursor;
    sfTexture *bloodtex;
    sfSprite *sprite;
    sfSprite *sprite_background;
    sfSprite *cursor;
    sfSprite *blood;
} entity_t;

#endif