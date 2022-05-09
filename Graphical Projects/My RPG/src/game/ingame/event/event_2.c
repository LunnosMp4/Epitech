/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** event_2.c
*/

#include "my_rpg.h"

static void game_pause(game_t *game)
{
    if (game->state == INGAME)
        game->state = PAUSE;
    else
        game->state = INGAME;
}

void exit_game_escape(game_t *game)
{
    if (game->state != GAME_OVER && game->state != WIN)
        game_pause(game);
    else if (game->state == GAME_OVER || game->state == WIN)
        sfRenderWindow_close(game->window);
}

void ingame_events_pt2(game_t *game, lnk_ltype_t *ltype)
{
    if (game->is_on_map == FRONT) {
        game->progress_bar->effect->is_bombing = true;
        if (get_seconds(game->progress_bar->effect->clock_bomb,
        game->progress_bar->effect->time_bomb) > rand() % (35 - 15) + 15) {
            sfSound_play(game->sounds[PLANE]);
            sfClock_restart(game->progress_bar->effect->clock_bomb);
        }
    }
    if (game->state != PAUSE && game->state != GAME_OVER)
        shoot(game, ltype->chr, &ltype->effects);
}
