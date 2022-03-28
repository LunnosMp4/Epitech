/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** texture.h
*/

#ifndef texture_H_
    #define texture_H_
    #include "my_defender.h"

typedef struct texture_s {
    sfTexture *texture;
    sfSprite *sprite;
    utils_t utils;
} texture_t;

#endif /* texture_H_ */
