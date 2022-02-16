/*
** EPITECH PROJECT, 2021
** Bootstrap MyRunner
** File description:
** animation.c
*/

#include "../include/my_runner.h"
#include "../include/object.h"

void set_repeated(object_t *object, fond_t *fond);
void set_texturerect(object_t *object, fond_t *fond);
void set_speed(object_t *object, fond_t *fond);

void set_background_animation(game_t *game, object_t *object, fond_t *fond)
{
    set_repeated(object, fond);
    fond->time = sfClock_getElapsedTime(fond->clock);
    fond->seconds = fond->time.microseconds / 1000000.0;
    if (fond->seconds > 0.01) {
        if (fond->rect.left == 800)
            fond->rect.left = 0;
        else
            set_speed(object, fond);
        set_texturerect(object, fond);
        sfClock_restart(fond->clock);
    }
}

void set_fox_run(game_t *game, object_t *object, fond_t *fond)
{
    sfVector2f def = {5, 0};
    fond->time2 = sfClock_getElapsedTime(fond->clock2);
    fond->seconds2 = fond->time2.microseconds / 1000000.0;
    if (fond->seconds2 > 0.1) {
        if (fond->rectfox.left == 2340)
            fond->rectfox.left = 0;
        else
            fond->rectfox.left = fond->rectfox.left + 468;
        sfSprite_setTextureRect(fond->fox->sprite, fond->rectfox);
        sfClock_restart(fond->clock2);
    }
}

void logspd(game_t *game, object_t *object, fond_t *fond)
{
    sfVector2f spd = {game->spd, 0};
    sfVector2f origin = {fond->nb, 450};
    sfVector2f origin2 = {fond->nb2, 450};
    sfSprite_move(fond->log->sprite, spd);
    sfSprite_move(fond->log2->sprite, spd);
    int pos = sfSprite_getPosition(fond->log->sprite).x;
    int pos2 = sfSprite_getPosition(fond->log2->sprite).x;
    if (pos < -50) {
        sfSprite_setPosition(fond->log->sprite, origin);
    }
    if (pos2 < -50) {
        sfSprite_setPosition(fond->log2->sprite, origin2);
    }
}