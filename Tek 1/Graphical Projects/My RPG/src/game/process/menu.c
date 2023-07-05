/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** process.c
*/

#include "my_rpg.h"

static void process_objects(game_t *game, lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;

    if (object->utils.type == BG)
        anime_sprite(object, (sfVector2f) {15, 2}, 0.11);
    if (ishover(game, object) && object->utils.type != BG)
        sfSprite_setTextureRect(object->sprite,
        (sfIntRect) {object->utils.rect.left + 240, 0, 240, 120});
    else if (object->utils.type != BG)
        sfSprite_setTextureRect(object->sprite, object->utils.rect);
    sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
}

void process_menu(menu_t *menu, game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        process_lmenu(game, menu, menu->main->buttons, menu_events);
    process_list(game, menu->main->buttons, process_objects);
    process_list(game, menu->main->texts, process_texts);
}
