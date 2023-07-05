/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** hurt.c
*/

#include "my_rpg.h"

void hurt(object_t *entity)
{
    if (get_seconds(entity->anim->clock, entity->anim->time) > 0.2)
        sfSprite_setColor(entity->sprite,
        sfColor_fromRGBA(255, 255, 255, 80));
    else
        sfSprite_setColor(entity->sprite, sfWhite);
    if (get_seconds(entity->anim->clock, entity->anim->time) > 0.3) {
        entity->stats->hp -= entity->event->damage;
        entity->event->is_hit = true;
        sfClock_restart(entity->anim->clock);
    }
}
