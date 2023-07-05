/*
** EPITECH PROJECT, 2021
** Bootstrap MyRunner
** File description:
** init_game.c
*/

#include "../include/my_runner.h"
#include "../include/object.h"

object_t *create_object (const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect)
{
    object_t *object = malloc(sizeof(object_t));
    object->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTextureRect(object->sprite, rect);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setPosition(object->sprite, pos);
    return object;
}