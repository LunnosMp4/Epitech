/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** forward
*/

#include "server.h"

int forward_north(int y, int max_y)
{
    if (y < 0)
        y = max_y - 1;
    return y;
}

int forward_south(int y, int max_y)
{
    if (y >= max_y)
        y = 0;
    return y;
}

int forward_east(int x, int max_x)
{
    if (x >= max_x)
        x = 0;
    return x;
}

int forward_west(int x, int max_x)
{
    if (x < 0)
        x = max_x - 1;
    return x;
}
