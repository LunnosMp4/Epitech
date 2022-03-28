/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** follow_cursor.c
*/

#include "my_defender.h"

void follow_cursor(game_t *game, sfSprite *sprite)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    sfSprite_setColor(sprite, sfColor_fromRGBA(255, 255, 255, 150));
    sfSprite_setPosition(sprite, (sfVector2f)
    {mouse_pos.x - RES, mouse_pos.y - RES});
}
