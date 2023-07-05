/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** set_direction_2.c
*/

#include "my_rpg.h"

void set_human_x(object_t *entity,
sfVector2f pentity, sfVector2f pentity2)
{
    if (pentity.x < pentity2.x) {
        entity->utils.rect.top = 64 + 128;
        entity->anim->rect.top = 64 + 128;
    } else if (pentity.x > pentity2.x) {
        entity->utils.rect.top = 32 + 128;
        entity->anim->rect.top = 32 + 128;
    }
}

void set_human_y(object_t *entity,
sfVector2f pentity, sfVector2f pentity2)
{
    if (pentity.y < pentity2.y) {
        entity->utils.rect.top = 0 + 128;
        entity->anim->rect.top = 0 + 128;
    } else if (pentity.y > pentity2.y) {
        entity->utils.rect.top = 96 + 128;
        entity->anim->rect.top = 96 + 128;
    }
}
