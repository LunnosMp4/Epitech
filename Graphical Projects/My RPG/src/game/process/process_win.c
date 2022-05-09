/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** process_win.c
*/

#include "my_rpg.h"

static void process_text_extra(game_t *game, text_t *text)
{
    if (text->utils.type == TEXT_DEAD2) {;
        sfVector2f min = {(sfView_getCenter(game->player).x - 500),
        sfView_getCenter(game->player).y + 60};
        sfText_setPosition(text->text, min);
        sfText_setColor(text->text, sfColor_fromRGBA(0, 255, 0, 200));
        sfText_setString(text->text, "Appuyez sur Echap pour quitter");
        sfRenderWindow_drawText(game->window, text->text, NULL);
    }
}

static void process_text(game_t *game, lnk_list_t *list)
{
    text_t *text = (text_t *) list->data;

    for (int i = 0; i != 200; i++)
        game->progress_bar->weather->cycle = i;
    if (text->utils.type == TEXT_DEAD) {
        sfVector2f min = {(sfView_getCenter(game->player).x - 500),
        sfView_getCenter(game->player).y - 120};
        sfText_setPosition(text->text, min);
        sfText_setCharacterSize(text->text, 50);
        sfText_setColor(text->text, sfColor_fromRGB(0, 255, 0));
        sfText_setString(text->text, "                      \
        Felicitation !\nVous avez battu le terrible Poutine !");
        sfRenderWindow_drawText(game->window, text->text, NULL);
    }
    process_text_extra(game, text);
}

void process_win(game_t *game, lnk_list_t *list)
{
    process_list(game, list, process_text);
}
