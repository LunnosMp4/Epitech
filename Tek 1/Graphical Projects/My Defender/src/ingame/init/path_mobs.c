/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** path_mobs.c
*/

#include "my_defender.h"

static int check_outmap(sfVector2i p_map, sfVector2i add)
{
    if (p_map.y + add.y <= MAPY && p_map.y + add.y >= 0 &&
    p_map.x + add.x <= MAPX && p_map.x + add.x >= 0)
        return 0;
    return 1;
}

static sfVector2i create_path(config_t *conf, sfVector2i p_map, sfVector2i way)
{
    if (way.y == 0 && way.x == 0) {
        p_map.x = WIDTH;
        return p_map;
    }
    while (conf->map[p_map.y + way.y][p_map.x + way.x] == 27)
        p_map = (sfVector2i) {p_map.x + way.x, p_map.y + way.y};
    conf->pos_steps[conf->steps] =
    (sfVector2f) {(p_map.x - way.x) * RES, (p_map.y - way.y) * RES};
    if (way.x == 0)
        conf->direction[conf->steps++] = (sfVector2f) {0, way.y};
    else
        conf->direction[conf->steps++] = (sfVector2f) {way.x, 0};
    return p_map;
}

static int change_direction(config_t *conf, sfVector2i p_map, sfVector2i way)
{
    if (conf->map[p_map.y + way.x][p_map.x + way.y] == 27)
        return 1;
    if (conf->map[p_map.y - way.x][p_map.x - way.y] == 27)
        return -1;
    return 0;
}

void path_mobs(config_t *conf)
{
    sfVector2i p_map = {0, 0};
    sfVector2i way = {0, 0};

    for (; p_map.y < MAPY && conf->map[p_map.y][0] != 27; p_map.y++)
        way.x = 1;
    conf->pos_steps[conf->steps++] =
    (sfVector2f) {(p_map.x - way.x) * RES, (p_map.y - way.y) * RES};
    while (!check_outmap(p_map, way)) {
        p_map = create_path(conf, p_map, way);
        if (check_outmap(p_map, way))
            break;
        if (way.x != 0 && way.y == 0)
            way = (sfVector2i)
            {0, change_direction(conf, p_map, (sfVector2i) {1, 0})};
        else if (way.y != 0 && way.x == 0)
            way = (sfVector2i)
            {change_direction(conf, p_map, (sfVector2i) {0, 1}), 0};
    }
}
