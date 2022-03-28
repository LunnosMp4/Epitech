/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** check.c
*/

#include "my_defender.h"

int check_map_isvalid(char *map, int i, sfVector2i p_id)
{
    if (p_id.x * RES > WIDTH || p_id.y * RES > HEIGHT - RES)
        return -1;
    for (int m = i + 3; i < m; i += 1)
        if (!map[i])
            return i;
    return i;
}
