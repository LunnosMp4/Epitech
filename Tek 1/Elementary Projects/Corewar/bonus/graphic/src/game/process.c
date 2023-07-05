/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** loop.c
*/

#include "graphic.h"

static void animation(game_t *game, object_t *btn)
{
    if (ishover(game->window, btn)) {
        anim_button_pressed(btn);
        if (!btn->anim.is_pressed)
            sfSound_play(game->sounds[SPRESSED]);
        btn->anim.is_pressed = true;
        game->btn = true;
    } else if (btn->anim.is_pressed) {
        sfSprite_setPosition(btn->sprite, btn->utils.pos);
        btn->anim.is_pressed = false;
    } else
        game->btn = false;
}

static void process_objects(game_t *game, UNUSED type_t *type,
lnk_tlist_t *list)
{
    object_t *btn = (object_t *) list->data;

    animation(game, btn);
    sfRenderWindow_drawSprite(game->window, btn->sprite, NULL);
}

static void process_texts(game_t *game, UNUSED type_t *type, lnk_tlist_t *list)
{
    text_t *text = (text_t *) list->data;

    sfRenderWindow_drawText(game->window, text->text, NULL);
}

void process_graphic(game_t *game, type_t *type)
{
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            process_events(game);
        sfRenderWindow_clear(game->window, game->clear_color);
        sfRenderWindow_drawSprite(game->window, type->bg->sprite, NULL);
        process_list(game, type, &type->buttons, process_objects);
        process_list(game, type, &type->texts, process_texts);
        sfRenderWindow_display(game->window);
    }
}
