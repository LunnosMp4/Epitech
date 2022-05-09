/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** animation.h
*/

#ifndef ANIMATION_H_
    #define ANIMATION_H_
    #include "my_rpg.h"

typedef struct animation_s {
    sfTime time;
    sfClock *clock;
    float seconds;
    sfIntRect rect;
} animation_t;

#endif /* ANIMATION_H_ */
