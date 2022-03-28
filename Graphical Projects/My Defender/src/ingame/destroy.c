/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** destroy.c
*/

#include "my_defender.h"

void destroy_object(UNUSED game_t *game, lnk_list_t *list)
{
    object_t *objects = (object_t *) list->data;

    sfSprite_destroy(objects->sprite);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    for (int i = 0; i != NB_MUSIC; i++)
        sfMusic_destroy(game->sounds->music[i]);
    free(game->sounds->music);
    free(game->sounds);
    free(game);
}
