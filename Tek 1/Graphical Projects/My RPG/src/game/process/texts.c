/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** texts.c
*/

#include "my_rpg.h"

void process_texts(game_t *game, lnk_list_t *list)
{
    text_t *text = (text_t *) list->data;

    if (text->utils.type == TEXT || text->utils.type == DIALOG)
        sfRenderWindow_drawText(game->window, text->text, NULL);
    if (text->utils.type == NB_VOL) {
        char *str_ammo =
        convert_int_to_text(game->volume, " %");
        sfText_setString(text->text, str_ammo);
        sfRenderWindow_drawText(game->window, text->text, NULL);
    }
}
