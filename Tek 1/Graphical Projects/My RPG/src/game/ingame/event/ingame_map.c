/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** event_map.c
*/

#include "my_rpg.h"

static void display_inmap(game_t *game, lnk_ltype_t *ltype)
{
    if (game->is_on_map == UKR)
        sfRenderWindow_drawSprite(game->window, ltype->npc->sprite, NULL);
    if (game->is_on_map == UKR || game->is_on_map == FRONT
    || game->is_on_map == RUS)
        sfRenderWindow_drawSprite(game->window, ltype->ovcoat->sprite, NULL);
    if (game->is_on_map == FRONT)
        process_ltype(game, *ltype, &ltype->enemy, process_enemies);
    if (game->is_on_map == FRONT || game->is_on_map == UKR)
        process_ltype(game, *ltype, &ltype->allies, process_allies);
    if (game->is_on_map == BOSS) {
        sfRenderWindow_drawSprite(game->window, ltype->poutine->sprite, NULL);
        process_poutine(game, ltype);
    }
}

void map_ingame(game_t *game, menu_t *menu, lnk_ltype_t *ltype)
{
    display_inmap(game, ltype);
    if (game->state == PAUSE)
        process_pause(menu, game);
    if (game->is_on_map == FRONT)
        init_front_russ(ltype, game);
    lifebar(game, ltype);
    process_list(game, ltype->interface, process_interface);
    process_ltype(game, *ltype, &ltype->text, gui_texts);
    if (game->state == STORY) {
        sfRenderWindow_drawSprite(game->window,
        ltype->dialog->background->sprite, NULL);
        sfRenderWindow_drawText(game->window, ltype->dialog->text, NULL);
        sfRenderWindow_drawSprite(game->window,
        ltype->dialog->faces->sprite, NULL);
    }
}
