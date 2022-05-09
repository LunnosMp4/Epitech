/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** gui_texts.c
*/

#include "my_rpg.h"

void second_gui_texts(game_t *game, lnk_ltype_t *ltype,
text_t *text, char *str_health)
{
    if (text->utils.type == HEALTH_TEXT) {
        sfText_setPosition(text->text, (sfVector2f) {
        sfView_getCenter(game->player).x + WIDTH / 2 - 140,
        sfView_getCenter(game->player).y + HEIGHT / 2 - 135});
        str_health =
        convert_int_to_text(ltype->chr->stats->health_nb, "");
        sfText_setString(text->text, str_health);
        sfRenderWindow_drawText(game->window, text->text, NULL);
    }
}

void gui_texts(game_t *game, lnk_ltype_t *ltype, lnk_list_t *list)
{
    text_t *text = (text_t *) list->data;
    char *str_ammo = NULL;
    char *str_health = NULL;
    char *str_ammo_max = malloc(sizeof(char) * 100);

    if (text->utils.type == AMMO) {
        sfText_setPosition(text->text, (sfVector2f) {
        sfView_getCenter(game->player).x + WIDTH / 2 - 130,
        sfView_getCenter(game->player).y + HEIGHT / 2 - 60});
        sfRenderWindow_drawText(game->window, text->text, NULL);
        str_ammo =
        convert_int_to_text(ltype->chr->weapon->stats->mun, " / ");
        str_ammo_max = convert_int(ltype->chr->weapon->stats->max_mun,
        "0123456789", str_ammo_max);
        sfText_setString(text->text, strcat_alloc(str_ammo, str_ammo_max));
    }
    second_gui_texts(game, ltype, text, str_health);
    lifebar_texts(game, ltype, text);
}
