/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** create_object_2.c
*/

#include "my_rpg.h"

void weapon_ak(TYPE type, attribute_t *stats)
{
    if (type == AK47) {
        stats->damage = 30;
        stats->duration = 2;
        stats->speed = 20;
        stats->mun = 30;
        stats->max_mun = 30;
        stats->cadency = 0.1;
        stats->pitch = 1.7;
    }
}

void weapon_glock(TYPE type, attribute_t *stats)
{
    if (type == GLOCK) {
        stats->damage = 40;
        stats->duration = 1;
        stats->speed = 40;
        stats->mun = 8;
        stats->max_mun = 8;
        stats->cadency = 0.5;
        stats->pitch = 1;
    }
}

void weapon_sniper(TYPE type, attribute_t *stats)
{
    if (type == SNIPER) {
        stats->damage = 100;
        stats->duration = 1;
        stats->speed = 80;
        stats->mun = 4;
        stats->max_mun = 4;
        stats->cadency = 0.8;
        stats->pitch = 0.6;
    }
}

attribute_t *set_stats_entity(TYPE type)
{
    attribute_t *stats = malloc(sizeof(attribute_t));
    char **arr = parsing_arg(read_file("assets/img/map/init_characters"));

    stats->hp = to_number(arr[4]);
    stats->state = ALIVE;
    if (type == CHR || type == HEROES)
        stats->speed = to_number(arr[9]);
    else
        stats->speed = 3;
    stats->atk = to_number(arr[5]);
    stats->def = to_number(arr[6]);
    stats->xp = to_number(arr[7]);
    stats->lvl = to_number(arr[8]);
    stats->health_nb = 1;
    stats->max_hp = 100;
    return stats;
}

void select_types(utils_t utl, sfTexture *texture, object_t *object)
{
    switch (utl.type) {
        case BG: sfSprite_scale(object->sprite, (sfVector2f) {2, 2.5});
        case IMG: break;
        case SNIPER:
        case AK47:
        case GLOCK: object->stats = set_stats_weapon(utl.type);
            break;
        case CHR:
        case HEROES:
        case ALLIES:
        case ENEMY: object->weapon = create_object((utils_t){{692, 47, 25, 15},
            {utl.pos.x + 16, utl.pos.y + 16}, AK47}, NULL, texture);
            object->stats = set_stats_entity(utl.type);
            break;
        case NPC:
        case QUEST_1:
        case QUEST_2:
        default: break;
    }
}
