/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** destroy.c
*/

#include "graphic.h"

void destroy_objects(UNUSED game_t *game, UNUSED type_t *type,
lnk_tlist_t *list)
{
    object_t *object = (object_t *) list->data;

    sfSprite_destroy(object->sprite);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    for (int i = 0; i < NB_SOUND; i++)
        sfSound_destroy(game->sounds[i]);
    free(game);
}
