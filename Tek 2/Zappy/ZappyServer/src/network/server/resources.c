/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** resources
*/

#include "server.h"

static void set_resources_next(map_t **current, int opt)
{
    switch (opt) {
    case 5:
        (*current)->phiras++;
        break;
    case 6:
        (*current)->thystame++;
        break;
    }
}

static void set_resources(map_t **current, int opt)
{
    switch (opt) {
    case 0:
        (*current)->food++;
        break;
    case 1:
        (*current)->linemate++;
        break;
    case 2:
        (*current)->deraumere++;
        break;
    case 3:
        (*current)->sibur++;
        break;
    case 4:
        (*current)->mendiane++;
        break;
    default:
        set_resources_next(current, opt);
        break;
    }
}

static bool set_in(map_t **tiles, int x, int y, int opt)
{
    map_t *current = (*tiles);
    for (; current != NULL; current = current->next) {
        if (current->x == x && current->y == y) {
            set_resources(&current, opt);
            return true;
        }
    }
    return false;
}

static void set_random_resources(map_t **tiles, int width, int height, int opt)
{
    int x = 0;
    int y = 0;

    do {
        x = rand() % width;
        y = rand() % height;
    } while (!set_in(tiles, x, y, opt));
}

map_t *setup_resources_in_map(map_t *tiles, int *resources_data,
int width, int height)
{
    for (int i = 0; i != 7; i++) {
        for (int j = 0; j != resources_data[i]; j++) {
            set_random_resources(&tiles, width, height, i);
        }
    }
    return tiles;
}
