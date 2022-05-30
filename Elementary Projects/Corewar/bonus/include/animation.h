/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** animation.h
*/

#ifndef ANIMATION_H_
    #define ANIMATION_H_
    #include "graphic.h"

typedef struct animation_s {
    sfClock *clock;
    sfTime time;
    bool is_pressed;
} animation_t;

#endif /* ANIMATION_H_ */
