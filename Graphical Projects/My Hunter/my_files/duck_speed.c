/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-loic.tisseyre
** File description:
** duck_speed.c
*/

#include "../include/my_structures.h"

void duck_speed(game_t *game)
{
    if (game->speed > 0)
        game->speed = game->speed + 1;
    else
        game->speed = - game->speed + 1;
}

void duck_rev_speed(game_t *game)
{
    if (game->speed > 0)
        game->speed = - game->speed - 1;
    else
        game->speed = game->speed - 1;
}