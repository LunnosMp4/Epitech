/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** inventory.c
*/

#include "my_rpg.h"

static void health_event(object_t *player)
{
    float i = 29;
    if (player->stats->hp + i >= player->stats->max_hp)
        i = (float) player->stats->max_hp - (float) player->stats->hp;
    for (int j = 0; j < i; j++)
        player->stats->hp += 1;
    player->stats->health_nb--;
}

void inventory(game_t *game, object_t *chr)
{
    if (game->event.key.code == sfKeyNum1)
        game->change_weap = 1;
    if (game->event.key.code == sfKeyNum2)
        game->change_weap = 2;
    if (game->event.key.code == sfKeyNum3)
        game->change_weap = 3;
    if (game->event.key.code == sfKeyE && chr->stats->health_nb > 0)
        health_event(chr);
    else if (game->is_on_map == UKR || game->is_on_map == RUS)
        game->progress_bar->effect->is_bombing = false;
}
