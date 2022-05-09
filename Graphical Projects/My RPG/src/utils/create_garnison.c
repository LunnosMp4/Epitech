/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** create_garnison.c
*/

#include "my_rpg.h"

void create_garnison_allie(utils_t utils, lnk_ltype_t *ltype, sfVector2i size)
{
    for (int i = 0; i < size.y; i++)
        for (int j = 0; j < size.x; j++) {
            create_object((utils_t) {utils.rect,
            {utils.pos.x + RES * j, utils.pos.y + RES * i}, utils.type},
            &ltype->allies, ltype->entities);
        }
}

void create_garnison_enemy(utils_t utils, lnk_ltype_t *ltype, sfVector2i size)
{
    for (int i = 0; i < size.y; i++)
        for (int j = 0; j < size.x; j++) {
            create_object((utils_t) {utils.rect,
            {utils.pos.x + RES * j, utils.pos.y + RES * i}, utils.type},
            &ltype->enemy, ltype->entities);
        }
}
