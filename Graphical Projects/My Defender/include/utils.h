/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** utils.h
*/

#ifndef UTILS_H_
    #define UTILS_H_
    #include "my_defender.h"

typedef struct utils_s {
    sfIntRect rect;
    sfVector2f pos;
    int id;
    TYPE type;
} utils_t;

#endif /* UTILS_H_ */
