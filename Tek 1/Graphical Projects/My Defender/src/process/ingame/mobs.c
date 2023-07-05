/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** ingame.c
*/

#include "my_defender.h"

void spawn_monster(lnk_ltype_t *ltype, game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds > game->conf->wave) {
        create_objects((utils_t) {{27 * RES, 0, RES, RES},
        game->conf->pos_steps[0], RES, MOB}, &ltype->mobs,
        ltype->objects);
        create_objects((utils_t) {{21 * RES, 0, RES, RES},
        {game->conf->pos_steps[0].x - 1, game->conf->pos_steps[0].y},
        RES, MOB}, &ltype->mobs,
        ltype->objects);
        game->conf->wave = (rand() % 6 * game->conf->difficulty)
        + game->seconds;
    }
    if (game->seconds > 20 * game->conf->difficulty) {
        sfClock_restart(game->clock);
        if (game->conf->difficulty > 0.2)
            game->conf->difficulty -= 0.07;
        game->conf->wave = 13 * game->conf->difficulty;
    }
}

static float mob_rotate(sfVector2f direction)
{
    float rotation = 0;

    if (direction.x < 0)
        rotation = 180;
    if (direction.y > 0)
        rotation = 90;
    if (direction.y < 0)
        rotation = -90;
    return rotation;
}

static void mob_move(game_t *game, object_t *mob)
{
    if (game->pause == 0)
        sfSprite_move(mob->sprite, game->conf->direction[mob->step]);
    if (sfSprite_getPosition(mob->sprite).x ==
    game->conf->pos_steps[mob->step].x + RES *
    game->conf->direction[mob->step].x &&
    sfSprite_getPosition(mob->sprite).y ==
    game->conf->pos_steps[mob->step].y +
    RES * game->conf->direction[mob->step].y) {
        mob->step += 1;
        sfSprite_setRotation(mob->sprite,
        mob_rotate(game->conf->direction[mob->step]));
    }
}

void animation_mob(game_t *game, object_t *mob)
{
    mob_move(game, mob);
    if (sfSprite_getPosition(mob->sprite).x > WIDTH - RES * 2) {
        sfSprite_setPosition(mob->sprite, game->conf->pos_steps[0]);
        mob->step = 1;
    }
}
