/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** read_map.c
*/

#include "my_defender.h"
#include <string.h>

int load_map(lnk_ltype_t *ltype, game_t *game)
{
    char path[25] = "assets/map/level-";
    char lvl = game->conf->set_map + '0';
    char *map = NULL;

    my_strncat(path, &lvl, 1);
    map = read_file(path);
    if (!map)
        return 84;
    if (read_map(map, ltype, game->conf) == 84)
        return 84;
    return 0;
}
