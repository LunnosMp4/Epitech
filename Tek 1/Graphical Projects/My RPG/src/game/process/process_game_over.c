/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** process_game_over.c
*/

#include "my_rpg.h"

static void process_text(game_t *game, lnk_list_t *list)
{
    text_t *text = (text_t *) list->data;

    for (int i = 0; i != 200; i++)
        game->progress_bar->weather->cycle = i;
    if (text->utils.type == TEXT_DEAD) {
        sfVector2f min = {(sfView_getCenter(game->player).x - 400),
        sfView_getCenter(game->player).y - 40};
        sfText_setPosition(text->text, min);
        sfRenderWindow_drawText(game->window, text->text, NULL);
    }
    if (text->utils.type == TEXT_DEAD2) {;
        sfVector2f min = {(sfView_getCenter(game->player).x - 460),
        sfView_getCenter(game->player).y + 60};
        sfText_setPosition(text->text, min);
        sfRenderWindow_drawText(game->window, text->text, NULL);
    }
}

void process_game_over(game_t *game, lnk_list_t *list)
{
    process_list(game, list, process_text);
}
