/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** flee.c
*/

#include "my_rpg.h"

void flee(object_t *entity, sfVector2f ptarget, sfVector2f pentity,
game_t *game)
{
    sfVector2f offset = {pentity.x - ptarget.x, pentity.y - ptarget.y};
    sfVector2f speed = {0, 0};

    if (offset.y > 0)
        speed.y = entity->stats->speed;
    else if (offset.y < 0)
        speed.y = -entity->stats->speed;
    if (offset.x > 0)
        speed.x = entity->stats->speed;
    else if (offset.x < 0)
        speed.x = -entity->stats->speed;
    limited_move(entity, speed, game);
}
