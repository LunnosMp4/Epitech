/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-loic.tisseyre
** File description:
** events.c
*/

#include "../include/my_runner.h"
#include "../include/object.h"

void reset_movement(game_t *game)
{
    if (game->y < 380) {
        game->velocityY += game->gravity;
    } else if (game->y > 380) {
        game->y = 380;
    }
    game->velocityY += game->accelerationY;
    game->y += game->velocityY;
}

void set_keybinds(game_t *game, sfEvent event,
object_t *object, fond_t *fond)
{
    if (event.type == sfEvtClosed || event.type ==
    sfEvtKeyPressed && event.key.code == sfKeyP) {
        if (game->pause == 0) {
            game->pause = 1;
            sfMusic_pause(fond->MainMusic);
        } else if (game->pause == 1) {
            game->pause = 0;
            sfMusic_play(fond->MainMusic);
        }
    }
    if (event.type == sfEvtClosed || event.type ==
    sfEvtKeyPressed && event.key.code == sfKeyEnter) {
        sfVector2f pos = {-1000, -1000};
        if (game->start != 1) {
            game->start = 1;
            sfSprite_setPosition(fond->start->sprite, pos);
            sfMusic_play(fond->MainMusic);
        }
    }
}

int analyse_events(game_t *game, sfEvent event,
object_t *object, fond_t *fond)
{
    int posy = sfSprite_getPosition(fond->fox->sprite).y;
    if (event.type == sfEvtClosed || event.type == sfEvtKeyPressed
    && event.key.code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (event.type == sfEvtClosed || event.type ==
    sfEvtKeyPressed && event.key.code == sfKeySpace) {
        game->jump = sfMusic_createFromFile("song/jump.wav");
        if (posy > 379) {
            sfMusic_play(game->jump);
            game->velocityY = -10;
        }
    }
    set_keybinds(game, event, object, fond);
    return 0;
}