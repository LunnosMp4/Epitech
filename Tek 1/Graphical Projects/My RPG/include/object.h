/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** object.h
*/

#ifndef OBJECT_H_
    #define OBJECT_H_
    #include "my_rpg.h"
    #include "animation.h"
    #include "attribute.h"

typedef struct object_s {
    sfSprite *sprite;
    sfVector2f pos;
    utils_t utils;
    event_t *event;
    attribute_t *stats;
    animation_t *anim;
    struct object_s *weapon;
} object_t;

object_t *create_object(utils_t utl, lnk_list_t **objects, sfTexture *texture);

#endif /* OBJECT_H_ */
