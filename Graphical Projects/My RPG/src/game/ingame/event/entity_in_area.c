/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** entity_inarea.c
*/

#include "my_rpg.h"

bool entity_in_area(object_t *object, sfVector2f target, float area)
{
    sfVector2f pos = sfSprite_getPosition(object->sprite);

    pos.x -= object->utils.rect.width / 2;
    pos.y += object->utils.rect.height / 2;
    if (pos.x > target.x - area && pos.x < target.x + area &&
        pos.y > target.y - area && pos.y < target.y + area)
        return true;
    return false;
}
