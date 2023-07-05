/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** building.c
*/

#include "my_defender.h"

void init_bar_buttons(lnk_ltype_t *ltype)
{
    create_objects((utils_t) {{RES * 6, 0, RES, RES},
    {40, 590}, MINI_TURRET, BUTTON}, &ltype->bulding, ltype->objects);
    create_objects((utils_t) {{RES * 2, 0, RES, RES},
    {40, 595}, MINI_TURRET, BUTTON}, &ltype->bulding, ltype->objects);
    create_objects((utils_t) {{RES * 17, 0, RES, RES},
    {155, 590}, MEDIUM_TURRET, BUTTON}, &ltype->bulding, ltype->objects);
    create_objects((utils_t) {{RES * 2, 0, RES, RES},
    {155, 595}, MEDIUM_TURRET, BUTTON}, &ltype->bulding, ltype->objects);
    create_objects((utils_t) {{RES * 18, 0, RES, RES},
    {275, 590}, LARGE_TURRET, BUTTON}, &ltype->bulding, ltype->objects);
    create_objects((utils_t) {{RES * 2, 0, RES, RES},
    {275, 595}, LARGE_TURRET, BUTTON}, &ltype->bulding, ltype->objects);
}
