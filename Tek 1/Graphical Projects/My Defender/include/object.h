/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** object.h
*/

#ifndef OBJECT_H_
    #define OBJECT_H_
    #include "my_defender.h"

typedef struct object_s {
    sfTexture *texture;
    sfSprite *sprite;
    int id;
    TYPE type;
    int step;
    utils_t utils;
} object_t;

#endif /* OBJECT_H_ */
