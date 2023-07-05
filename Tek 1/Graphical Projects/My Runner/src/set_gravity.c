/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-loic.tisseyre
** File description:
** set_gravity.c
*/

#include "../include/my_runner.h"

void set_movement(game_t *game)
{
    game->score = 1;
    game->x = 100;
    game->y = -380;
    game->velocityY = 0;
    game->accelerationY = 0;
    game->gravity = 0.5;
}