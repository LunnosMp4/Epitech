/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** ingame.c
*/

#include "my_defender.h"

void build_towers(game_t *game, lnk_list_t *list, lnk_ltype_t *ltype)
{
    object_t *object = (object_t *) list->data;

    sfSprite_setScale(object->sprite, (sfVector2f) {2, 2});
    sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    if (sfMouse_isButtonPressed(sfMouseRight) && game->grab != 0)
        turret_isreleased(game, ltype);
    if (game->grab == MINI_TURRET && object->utils.id == MINI_TURRET &&
    object->utils.type == BUTTON)
        follow_cursor(game, object->sprite);
    if (game->grab == MEDIUM_TURRET && object->utils.id == MEDIUM_TURRET &&
    object->utils.type == BUTTON)
        follow_cursor(game, object->sprite);
    if (game->grab == LARGE_TURRET && object->utils.id == LARGE_TURRET &&
    object->utils.type == BUTTON)
        follow_cursor(game, object->sprite);
    replace_turret_btn(game, object);
}
