/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** popup_inv.c
*/

#include "my_rpg.h"

void process_inv_popup(game_t *game, object_t *object, sfVector2f min)
{
    if (object->utils.type == POPUP_INV) {
        min = (sfVector2f) {(sfView_getCenter(game->player).x + WIDTH / 2 -
        object->utils.rect.width + 5),
        sfView_getCenter(game->player).y + HEIGHT / 2 -
        object->utils.rect.height + 5};
        sfSprite_setPosition(object->sprite, min);
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    }
}
