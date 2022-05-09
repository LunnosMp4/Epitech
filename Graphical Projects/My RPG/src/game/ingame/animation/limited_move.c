/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** limited_move.c
*/

#include "my_rpg.h"

static sfVector2f limited_map_max(object_t *entity,
sfVector2f move, game_t *game, sfVector2i map)
{
    if (move.y > 0 && game->map_cols[map.y + 1][map.x] == '1'
    && game->map_cols[map.y][map.x] == '1')
        move = (sfVector2f) {0, 0};
    if (entity->pos.x < 0)
        move = (sfVector2f){2, 0};
    else if (entity->pos.x > 6400 - ENTW)
        move = (sfVector2f){-2, 0};
    if (entity->pos.y < 0)
        move = (sfVector2f){0, 2};
    else if (entity->pos.y > 6400 - ENTH)
        move = (sfVector2f){0, -2};
    return move;
}

void limited_move(object_t *entity, sfVector2f move, game_t *game)
{
    sfVector2i map = (sfVector2i)
    {((int) entity->pos.x / 64), (int) entity->pos.y / 64 + 1};

    if (move.x < 0 && game->map_cols[map.y][map.x - 1] == '1'
    && game->map_cols[map.y][map.x] == '1')
        move = (sfVector2f) {0, 0};
    if (move.y < 0 && game->map_cols[map.y - 1][map.x] == '1'
    && game->map_cols[map.y][map.x] == '1')
        move = (sfVector2f) {0, 0};
    if (move.x > 0 && game->map_cols[map.y][map.x + 1] == '1'
    && game->map_cols[map.y][map.x] == '1')
        move = (sfVector2f) {0, 0};
    move = limited_map_max(entity, move, game, map);
    sfSprite_move(entity->weapon->sprite, move);
    sfSprite_move(entity->sprite, move);
}
