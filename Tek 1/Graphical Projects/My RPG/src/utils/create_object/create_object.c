/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** create_object.c
*/

#include "my_rpg.h"

attribute_t *set_stats_weapon(TYPE type)
{
    attribute_t *stats = malloc(sizeof(attribute_t));

    weapon_ak(type, stats);
    weapon_glock(type, stats);
    weapon_sniper(type, stats);
    return stats;
}

event_t *create_event(void)
{
    event_t *event = malloc(sizeof(event_t));

    event->is_hit = false;
    event->damage = 0;
    event->target = (sfVector2f) {-1, -1};
    return event;
}

object_t *create_object(utils_t utl, lnk_list_t **objects, sfTexture *texture)
{
    object_t *object = malloc(sizeof(object_t));

    object->event = create_event();
    object->anim = malloc(sizeof(animation_t));
    object->anim->clock = sfClock_create();
    object->anim->rect = utl.rect;
    object->sprite = sfSprite_create();
    object->utils = utl;
    sfSprite_setPosition(object->sprite, object->utils.pos);
    sfSprite_setTexture(object->sprite, texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, object->utils.rect);
    if (object->utils.type == HEROES)
        sfSprite_setScale(object->sprite, (sfVector2f) {1.5, 1.5});
    select_types(utl, texture, object);
    if (objects)
        add_node(object, objects);
    return object;
}
