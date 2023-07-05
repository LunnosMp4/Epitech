/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** pause.c
*/

#include "my_rpg.h"

static void process_text(game_t *game, lnk_list_t *list)
{
    text_t *text = (text_t *) list->data;

    if (text->utils.type == TEXT_P) {
        sfText_setPosition(text->text, (sfVector2f)
        {sfView_getCenter(game->player).x - 130,
        sfView_getCenter(game->player).y - 300});
        sfRenderWindow_drawText(game->window, text->text, NULL);
    }
}

static void process_buttons(game_t *game, object_t *object)
{
    if (object->utils.type == BTN_PLAY) {
        sfSprite_setPosition(object->sprite, (sfVector2f)
        {sfView_getCenter(game->player).x - 120,
        sfView_getCenter(game->player).y - 150});
    }
    if (object->utils.type == BTN_EXIT) {
        sfSprite_setPosition(object->sprite, (sfVector2f)
        {sfView_getCenter(game->player).x - 120,
        sfView_getCenter(game->player).y});
    }
}

static void process_objects(game_t *game, lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;

    if (ishover(game, object) && object->utils.type != POPUP_P
    && object->utils.type != POPUP_MAP && object->utils.type != POPUP_BARS)
        sfSprite_setTextureRect(object->sprite,
        (sfIntRect) {object->utils.rect.left + 240, 0, 240, 120});
    else
        sfSprite_setTextureRect(object->sprite, object->utils.rect);
    if (object->utils.type == POPUP_P) {
        sfSprite_setScale(object->sprite, (sfVector2f) {1.25, 1.5});
        sfSprite_setRotation(object->sprite, 90);
        sfSprite_setPosition(object->sprite, (sfVector2f)
        {sfView_getCenter(game->player).x + 190,
        sfView_getCenter(game->player).y - 300});
    }
    process_buttons(game, object);
    sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
}

void process_pause(menu_t *menu, game_t *game)
{
    process_list(game, menu->ingame->buttons, process_objects);
    process_list(game, menu->ingame->texts, process_text);
}
