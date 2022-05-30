/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** event.c
*/

#include "graphic.h"

static void play_sound(game_t *game)
{
    static bool state = true;

    if (state) {
        sfSound_play(game->sounds[SPLAY]);
        state = false;
    } else {
        sfSound_play(game->sounds[SSTOP]);
        state = true;
    }
}

void process_events(game_t *game)
{
    if (game->event.type == sfEvtClosed || (game->event.type == sfEvtKeyPressed
    && game->event.key.code == sfKeyEscape)) {
        sfSound_play(game->sounds[SQUIT]);
        while (sfSound_getStatus(game->sounds[SQUIT]) == sfPlaying);
        sfRenderWindow_close(game->window);
    }
    if (&game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && game->btn)
        play_sound(game);
}
