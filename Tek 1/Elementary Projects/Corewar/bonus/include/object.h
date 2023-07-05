/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** object.h
*/

#ifndef OBJECT_H_
    #define OBJECT_H_
    #include "graphic.h"

typedef struct object_s {
    sfSprite *sprite;
    utils_t utils;
    animation_t anim;
} object_t;

#endif /* OBJECT_H_ */
