/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** particles.h
*/

#include "my_rpg.h"

typedef struct particles {
    sfRectangleShape *shape;
    sfVector2f pos;
    sfClock *clock;
    sfTime *time;
} particles_t;
