/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** ishover.c
*/

#include "my_rpg.h"

bool ishover(game_t *game, object_t *object)
{
    sfVector2i curs_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = sfSprite_getPosition(object->sprite);
    sfVector2f curs_pos_ingame = sfRenderWindow_mapPixelToCoords(game->window,
    curs_pos, game->player);
    float curs_x = 0;
    float curs_y = 0;

    if (game->state == MENU || game->state == SETTINGS) {
        curs_x = curs_pos.x;
        curs_y = curs_pos.y;
    } else {
        curs_x = curs_pos_ingame.x;
        curs_y = curs_pos_ingame.y;
    }
    if (curs_x >= pos.x && curs_x <= pos.x + object->utils.rect.width
    && curs_y >= pos.y && curs_y <= pos.y + object->utils.rect.height)
        return true;
    return false;
}
