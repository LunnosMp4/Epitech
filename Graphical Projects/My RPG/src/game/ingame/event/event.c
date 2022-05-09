/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** event.c
*/

#include "my_rpg.h"

static void mini_map(game_t *game)
{
    if (game->event.key.code == sfKeyP)
        if (sfView_getSize(game->minimap).x > 500)
        sfView_setSize(game->minimap, (sfVector2f)
        {sfView_getSize(game->minimap).x / 1.1,
        sfView_getSize(game->minimap).y / 1.1});
    if (game->event.key.code == sfKeyM)
        if (sfView_getSize(game->minimap).x < 2700)
        sfView_setSize(game->minimap, (sfVector2f)
        {sfView_getSize(game->minimap).x / 0.9,
        sfView_getSize(game->minimap).y / 0.9});
}

static void take_health(game_t *game, lnk_ltype_t *ltype, lnk_list_t *list)
{
    object_t *object = (object_t *) list->data;
    sfVector2f pos;

    if (object->utils.type == HEALTH_RD) {
        pos = sfSprite_getPosition(object->sprite);
        if (game->event.key.code == sfKeyA &&
        entity_in_area(ltype->chr, pos, 100) == true) {
            ltype->chr->stats->health_nb++;
            delete_node(&list);
        }
    }
    if (object->utils.type == HONEY) {
        pos = sfSprite_getPosition(object->sprite);
        if (game->event.key.code == sfKeyA &&
        entity_in_area(ltype->chr, pos, 100))
            game->honney = true;
    }
}

void ingame_events(game_t *game, lnk_ltype_t *ltype)
{
    process_ltype(game, *ltype, &ltype->interface, take_health);
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtKeyPressed) {
        history(game, ltype);
        inventory(game, ltype->chr);
        mini_map(game);
        if (game->event.key.code == sfKeyEscape)
            exit_game_escape(game);
        ingame_events_pt2(game, ltype);
    }
}
