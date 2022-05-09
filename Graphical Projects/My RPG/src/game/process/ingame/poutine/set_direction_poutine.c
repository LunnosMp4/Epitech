/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** set_direction.c
*/

#include "my_rpg.h"

static void set_bear_x(object_t *entity,
sfVector2f pentity, sfVector2f pentity2)
{
    if (pentity.x < pentity2.x) {
        entity->utils.rect.top = 128;
        entity->anim->rect.top = 128;
    } else if (pentity.x > pentity2.x) {
        entity->utils.rect.top = 64;
        entity->anim->rect.top = 64;
    }
}

static void set_bear_y(object_t *entity,
sfVector2f pentity, sfVector2f pentity2)
{
    if (pentity.y < pentity2.y) {
        entity->utils.rect.top = 0;
        entity->anim->rect.top = 0;
    } else if (pentity.y > pentity2.y) {
        entity->utils.rect.top = 192;
        entity->anim->rect.top = 192;
    }
}

static void set_direction_x(object_t *entity,
sfVector2f pentity, sfVector2f pentity2)
{
    if (entity->utils.rect.left >= 120 &&
    entity->utils.rect.left <= 230) {
        set_human_x(entity, pentity, pentity2);
    } else if (entity->utils.rect.left >= 752)
        set_bear_x(entity, pentity, pentity2);
}

static void set_direction_y(object_t *entity,
sfVector2f pentity, sfVector2f pentity2)
{
    if (entity->utils.rect.left >= 120 &&
    entity->utils.rect.left <= 230) {
        set_human_y(entity, pentity, pentity2);
    } else if (entity->utils.rect.left >= 752)
        set_bear_y(entity, pentity, pentity2);
}

void set_poutine_direction(object_t *entity, sfVector2f pentity)
{
    sfVector2f pentity2 = sfSprite_getPosition(entity->sprite);

    set_direction_y(entity, pentity, pentity2);
    set_direction_x(entity, pentity, pentity2);
    if (pentity.x != pentity2.x || pentity.y != pentity2.y) {
        anime_sprite(entity, (sfVector2f) {3, 1}, 0.5);
    }
}
