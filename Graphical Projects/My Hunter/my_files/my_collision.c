/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-loic.tisseyre
** File description:
** my_collision.c
*/

#include "../include/my_structures.h"

sfBool collision2(game_t *game, entity_t *entity)
{
    int pos_entity1x = sfMouse_getPosition(game->window).x;
    int pos_entity1y = sfMouse_getPosition(game->window).y;
    int pos_entity2x = sfSprite_getPosition(entity->sprite).x;
    int pos_entity2y = sfSprite_getPosition(entity->sprite).y;

    if ((pos_entity1x >= pos_entity2x - 100 && \
    pos_entity1x <= pos_entity2x + 100)
    && (pos_entity1y >= pos_entity2y - 100 && \
    pos_entity1y <= pos_entity2y + 100))
        return sfTrue;
    else
        return sfFalse;
}