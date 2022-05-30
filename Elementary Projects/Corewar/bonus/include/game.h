/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** game.h
*/

#ifndef GAME_H
    #define GAME_H
    #include "graphic.h"
    #define NB_SOUND  5
    #define SPRESSED  0
    #define SPLAY     1
    #define SSTOP     2
    #define SINFO     3
    #define SQUIT     4

typedef enum {BTN, BG, IMG, TEXT} TYPE;

typedef struct game {
    sfRenderWindow *window;
    sfColor clear_color;
    sfEvent event;
    sfSound **sounds;
    sfText *text;
    bool btn;
} game_t;

game_t *create_game(sfVideoMode mode, sfColor clear_color);

#endif /* GAME_H_ */
