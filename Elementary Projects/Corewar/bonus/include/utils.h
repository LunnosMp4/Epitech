/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** utils.h
*/

#ifndef UTILS_H_
    #define UTILS_H_
    #include "graphic.h"

typedef struct utils_s {
    sfIntRect rect;
    sfVector2f pos;
    TYPE type;
} utils_t;

typedef struct utils_txt_s {
    sfVector2f pos;
    TYPE type;
    int size;
    char *string;
    sfColor color;
} utils_txt_t;

#endif /* UTILS_H_ */
