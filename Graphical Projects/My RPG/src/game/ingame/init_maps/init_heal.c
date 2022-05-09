/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** init_heal.c
*/

#include "my_rpg.h"

void init_heal(lnk_ltype_t *ltype, game_t *game)
{
    static int i;

    for (; i < 30; i++) {
        create_object((utils_t) {{710, 70, 18, 14},
        spawn_random(0, 6400, game), HEALTH_RD},
        &ltype->interface, ltype->entities);
    }
}
