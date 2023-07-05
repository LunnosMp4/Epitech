/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** linked_ltype.h
*/

#ifndef LINKED_LTYPE_H_
    #define LINKED_LTYPE_H_
    #include "my_defender.h"

    #define MINI_TURRET 1
    #define MEDIUM_TURRET 2
    #define LARGE_TURRET 3

typedef struct lnk_ltype_s {
    lnk_list_t *mobs;
    lnk_list_t *bulding;
    lnk_list_t *entities;
    lnk_list_t *textures;
    sfTexture *objects;
    sfTexture *texture;
    int newid;
} lnk_ltype_t;

#endif /* LINKED_LTYPE_H_ */
