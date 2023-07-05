/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** get_seconds.c
*/

#include "my_rpg.h"

float get_seconds(sfClock *clock, sfTime time)
{
    float seconds = 0;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return seconds;
}
