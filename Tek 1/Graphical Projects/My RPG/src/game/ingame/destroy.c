/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** destroy.c
*/

#include "my_rpg.h"

void destroy_object(UNUSED game_t *game, UNUSED lnk_ltype_t *ltype,
lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;

    sfSprite_destroy(object->sprite);
}

void destroy_game(game_t *game)
{
    for (int i = 0; i != NB_MUSIC - 1; i++)
        sfMusic_destroy(game->music[i]);
    for (int i = 0; i != NB_SOUND - 1; i++)
        sfSound_destroy(game->sounds[i]);
    sfRenderWindow_destroy(game->window);
    sfView_destroy(game->player);
    sfView_destroy(game->minimap);
    free(game->sounds);
    free(game->music);
    free(game);
}
