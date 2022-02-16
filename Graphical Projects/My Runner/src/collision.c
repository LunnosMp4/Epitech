/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-loic.tisseyre
** File description:
** collision.c
*/

#include "../include/my_runner.h"
#include "../include/object.h"

sfBool collision(game_t *game, object_t *object, fond_t *fond)
{
    int pos_entity1x = sfSprite_getPosition(fond->log->sprite).x;
    int pos_entity1y = sfSprite_getPosition(fond->log->sprite).y;
    int pos_entity2x = sfSprite_getPosition(fond->fox->sprite).x;
    int pos_entity2y = sfSprite_getPosition(fond->fox->sprite).y;

    if ((pos_entity1x + 50 >= pos_entity2x &&
    pos_entity1x <= pos_entity2x + 100)
    && (pos_entity1y + 50 >= pos_entity2y &&
    pos_entity1y <= pos_entity2y + 100))
        return sfTrue;
    else
        return sfFalse;
}

sfBool collision2(game_t *game, object_t *object, fond_t *fond)
{
    int pos_entity1x = sfSprite_getPosition(fond->log2->sprite).x;
    int pos_entity1y = sfSprite_getPosition(fond->log2->sprite).y;
    int pos_entity2x = sfSprite_getPosition(fond->fox->sprite).x;
    int pos_entity2y = sfSprite_getPosition(fond->fox->sprite).y;

    if ((pos_entity1x + 50 >= pos_entity2x &&
    pos_entity1x <= pos_entity2x + 100)
    && (pos_entity1y + 50 >= pos_entity2y &&
    pos_entity1y <= pos_entity2y + 100))
        return sfTrue;
    else
        return sfFalse;
}