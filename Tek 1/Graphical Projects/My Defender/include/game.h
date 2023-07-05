/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** game.h
*/

#ifndef GAME_H
    #define GAME_H
    #define WIDTH 1152
    #define HEIGHT 672
    #define NB_MUSIC 4
    #define RES 32
    #define MAPX WIDTH / RES
    #define MAPY HEIGHT / RES
    #include "my_defender.h"

typedef enum {MENU, INGAME, START, PAUSE, INFO, GAME_OVER, SELECT} GAME;
typedef enum {TEXTURE, MOB, BUILDING, ENTITY, BUTTON, IMG} TYPE;

typedef struct game {
    sfRenderWindow *window;
    sounds_t *sounds;
    sfColor clear_color;
    sfEvent event;
    GAME state;
    sfClock *clock;
    sfTime time;
    float seconds;
    text_t *text;
    config_t *conf;
    int id;
    int pause;
    int grab;
} game_t;

game_t *create_game(sfVideoMode mode, sfColor clear_color);

#endif /* GAME_H_ */
