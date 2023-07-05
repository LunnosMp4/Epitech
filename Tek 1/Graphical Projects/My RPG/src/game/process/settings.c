/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** settings.c
*/

#include "my_rpg.h"

static void process_objects(game_t *game, lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;

    if (object->utils.type == BG)
        anime_sprite(object, (sfVector2f) {15, 2}, 0.11);
    if (ishover(game, object) && object->utils.type != BG &&
    object->utils.type != POPUP)
        sfSprite_setTextureRect(object->sprite,
        (sfIntRect) {object->utils.rect.left + 240, 0, 240, 120});
    else if (object->utils.type != BG)
        sfSprite_setTextureRect(object->sprite, object->utils.rect);
    if (object->utils.type == POPUP) {
        sfSprite_setScale(object->sprite, (sfVector2f) {2.4, 2.7});
        sfSprite_setColor(object->sprite, (sfColor) {255, 255, 255, 240});
    }
    sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
}

void process_settings(menu_t *menu, game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        process_lmenu(game, menu, menu->settings->buttons, settings_events);
    process_list(game, menu->settings->buttons, process_objects);
    process_list(game, menu->settings->texts, process_texts);
}
