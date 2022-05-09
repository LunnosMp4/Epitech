/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** character.h
*/

#ifndef PROGRESS_BAR_H
    #define PROGRESS_BAR_H
    #include "my_rpg.h"

typedef struct weather {
    sfRectangleShape *brightness;
    int min;
    int max;
    bool day;
    int cycle;
    sfClock *clock;
    sfTime time;
} weather_t;

typedef struct effect {
    bool is_bombing;
    sfClock *clock;
    sfTime time;
    sfClock *clock_bomb;
    sfTime time_bomb;
} effect_t;

typedef struct progress_bar {
    sfRectangleShape *health;
    sfRectangleShape *xp;
    weather_t *weather;
    effect_t *effect;
} progress_bar_t;

#endif
