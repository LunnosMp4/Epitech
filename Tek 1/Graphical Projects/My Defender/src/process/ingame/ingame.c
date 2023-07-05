/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** ingame.c.c
*/

#include "my_defender.h"

void process_sprite(game_t *game, lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;

    switch (object->utils.type) {
        case MOB: animation_mob(game, object);
            break;
        default: break;
    }
    sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
}

void process_texture(game_t *game, lnk_list_t *list)
{
    texture_t *textures = (texture_t *) list->data;

    sfRenderWindow_drawSprite(game->window, textures->sprite, NULL);
}

void process_game_button(game_t *game, lnk_list_t *buttons)
{
    button_t *button = (button_t *) buttons->data;

    if (button->id == BAR)
        sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
}
