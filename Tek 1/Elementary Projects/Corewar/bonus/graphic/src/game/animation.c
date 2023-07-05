/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** animation.c
*/

#include "graphic.h"

void anim_button_pressed(object_t *btn)
{
    sfVector2f move = {0, 0};
    float s = sfClock_getElapsedTime(btn->anim.clock).microseconds / 1000000.0;

    move.y = 0.2;
    if (s > 1) {
        move.y = -0.2;
        if (s > 2)
            sfClock_restart(btn->anim.clock);
    }
    sfSprite_move(btn->sprite, move);
}
