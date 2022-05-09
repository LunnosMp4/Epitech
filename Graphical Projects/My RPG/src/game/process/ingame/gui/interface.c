/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** allies.c
*/

#include "my_rpg.h"

void process_minimap_texts(game_t *game, lnk_list_t *list)
{
    text_t *text = (text_t *) list->data;

    if (text->utils.type == TEXT_MAP && game->is_on_map == UKR)
        sfRenderWindow_drawText(game->window, text->text, NULL);
}

void process_minimap(game_t *game, lnk_ltype_t *ltype)
{
    sfRenderWindow_drawSprite(game->window, ltype->map->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, ltype->chr->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, ltype->ovcoat->sprite, NULL);
    process_list(game, ltype->text, process_minimap_texts);
}

void process_interface(game_t *game, lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;

    process_interface_popup(game, object);
    if (object->utils.type == POPUP_MAP) {
        sfVector2f min = {(sfView_getCenter(game->player).x + WIDTH / 2) -
        sfView_getViewport(game->minimap).width * WIDTH + 20,
        sfView_getCenter(game->player).y - HEIGHT / 2 - 10};
        sfSprite_setScale(object->sprite, (sfVector2f) {0.7, 1});
        sfSprite_setPosition(object->sprite, min);
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    }
    if (object->utils.type == POPUP_BARS) {
        sfVector2f min = {(sfView_getCenter(game->player).x - WIDTH / 2),
        sfView_getCenter(game->player).y +
        HEIGHT / 2 - object->utils.rect.height * 2};
        sfSprite_setPosition(object->sprite, min);
        sfSprite_setScale(object->sprite, (sfVector2f) {2, 2});
        sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
    }
}
