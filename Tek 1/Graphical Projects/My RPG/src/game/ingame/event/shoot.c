/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** shoot.c
*/

#include "my_rpg.h"

static void shoot_events(game_t *game, object_t *entity,
lnk_list_t **effects, float seconds)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)
    && seconds > entity->weapon->stats->cadency
    && entity->weapon->stats->mun > 0) {
        sfSound_play(sfSound_copy(game->sounds[SHOOT]));
        create_object((utils_t) {{640, 60, 16, 4},
        (sfVector2f) {sfSprite_getPosition(entity->sprite).x + 13,
        sfSprite_getPosition(entity->sprite).y + 20},
        BULLET}, effects, (sfTexture *) sfSprite_getTexture(entity->sprite));
        entity->weapon->stats->mun--;
        sfClock_restart(entity->weapon->anim->clock);
    }
}

static void wait_second(game_t *game, object_t *entity, float seconds)
{
    if (seconds > 0.4) {
        if (entity->weapon->stats->mun != entity->weapon->stats->max_mun)
            sfSound_play(game->sounds[RELOAD]);
        entity->weapon->stats->mun = entity->weapon->stats->max_mun;
        sfClock_restart(game->clock);
    }
}

void shoot(game_t *game, object_t *entity, lnk_list_t **effects)
{
    float seconds =
    get_seconds(entity->weapon->anim->clock, entity->weapon->anim->time);

    if (game->event.key.code == sfKeyR)
        wait_second(game, entity, seconds);
    sfSound_setPitch(game->sounds[SHOOT], entity->weapon->stats->pitch);
    shoot_events(game, entity, effects, seconds);
}
