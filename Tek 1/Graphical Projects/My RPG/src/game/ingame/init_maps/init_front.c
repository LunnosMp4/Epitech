/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** init_front.c
*/

#include "my_rpg.h"

sfVector2f spawn_random(int begin, int end, game_t *game)
{
    sfVector2f pos_rand =
    (sfVector2f) {(rand() % (end - begin)) + begin, rand() % 6400};

    while (game->map_cols[(int)(pos_rand.y) / 64]
    [(int) (pos_rand.x) / 64] == '1')
        pos_rand =
        (sfVector2f) {(rand() % (end - begin)) + begin, rand() % 6400};
    return pos_rand;
}

void init_front_russ(lnk_ltype_t *ltype, game_t *game)
{
    static int i = 0;

    if (i == 0)
        create_object((utils_t) {{0, 128, RES, RES},
        spawn_random(3200, 6400, game), HEROES},
        &ltype->enemy, ltype->entities);
    for (; i < 250; i++) {
        create_object((utils_t) {{512, 0, RES, RES},
        spawn_random(3200, 6400, game), ENEMY}, &ltype->enemy,
        ltype->entities);
    }
    create_object((utils_t) {{0, 0, 0, 0},
    {0, 0}, INVISIBLE}, &ltype->enemy, ltype->entities);
    for (; i < 400; i++) {
        create_object((utils_t) {{384, 128, RES, RES},
        spawn_random(0, 3200, game), ALLIES}, &ltype->allies,
        ltype->entities);
    }
    for (; i < 500; i++) {
        create_object((utils_t) {{256, 128, RES, RES},
        spawn_random(0, 3200, game), ALLIES}, &ltype->allies,
        ltype->entities);
    }
}
