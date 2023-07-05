/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** set_direction.c
*/

#include "my_rpg.h"

static void set_direction_x(object_t *entity,
sfVector2f pentity, sfVector2f pentity2)
{
    int top = 0;

    if (entity->utils.rect.top >= 128)
        top = 128;
    if (pentity.x < pentity2.x) {
        entity->utils.rect.top = 64 + top;
        entity->anim->rect.top = 64 + top;
        entity->weapon->utils.rect = (sfIntRect) {667, 0, 25, 15};
        sfSprite_setPosition(entity->weapon->sprite,
        (sfVector2f) {pentity.x + 20, pentity.y + 14});
    } else if (pentity.x > pentity2.x) {
        entity->utils.rect.top = 32 + top;
        entity->anim->rect.top = 32 + top;
        entity->weapon->utils.rect = (sfIntRect) {707, 180, 28, 15};
        sfSprite_setPosition(entity->weapon->sprite,
        (sfVector2f) {pentity.x - 5, pentity.y + 12});
    }
    sfSprite_setTextureRect(entity->weapon->sprite,
    entity->weapon->utils.rect);
}

static void set_direction_y(object_t *entity,
sfVector2f pentity, sfVector2f pentity2)
{
    int top = 0;

    if (entity->utils.rect.top >= 128)
        top = 128;
    if (pentity.y < pentity2.y) {
        entity->utils.rect.top = 0 + top;
        entity->anim->rect.top = 0 + top;
        entity->weapon->utils.rect = (sfIntRect) {689, 99, 9, 16};
        sfSprite_setPosition(entity->weapon->sprite,
        (sfVector2f) {pentity.x + 3, pentity.y + 20});
    } else if (pentity.y > pentity2.y) {
        entity->utils.rect.top = 96 + top;
        entity->anim->rect.top = 96 + top;
        entity->weapon->utils.rect = (sfIntRect) {2000, 0, 28, 15};
    }
    sfSprite_setTextureRect(entity->weapon->sprite,
    entity->weapon->utils.rect);
}

void set_entity_direction(object_t *entity, sfVector2f pentity)
{
    sfVector2f pentity2 = sfSprite_getPosition(entity->sprite);

    if (entity->utils.type == DEAD)
        return;
    set_direction_y(entity, pentity, pentity2);
    set_direction_x(entity, pentity, pentity2);
    if (pentity.x != pentity2.x || pentity.y != pentity2.y)
        anime_sprite(entity, (sfVector2f) {3, 1}, 0.5);
    else {
        entity->anim->rect.left = entity->utils.rect.left + 64;
        sfSprite_setTextureRect(entity->sprite, entity->anim->rect);
    }
}
