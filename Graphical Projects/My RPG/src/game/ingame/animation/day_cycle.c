/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** day_cycle.c
*/

#include "my_rpg.h"

void day_cycle(game_t *game)
{
    sfRectangleShape_setPosition(game->progress_bar->weather->brightness,
    (sfVector2f) {sfView_getCenter(game->player).x - WIDTH / 2 - 100,
    sfView_getCenter(game->player).y - HEIGHT / 2 - 100});
    sfVector2f size3 = {WIDTH + 200, HEIGHT + 200};
    sfRectangleShape_setSize(game->progress_bar->weather->brightness, size3);
    sfRectangleShape_setFillColor(game->progress_bar->weather->brightness,
    sfColor_fromRGBA(0, 0, 0, game->progress_bar->weather->cycle));
    sfRenderWindow_drawRectangleShape(game->window,
    game->progress_bar->weather->brightness, NULL);
}
