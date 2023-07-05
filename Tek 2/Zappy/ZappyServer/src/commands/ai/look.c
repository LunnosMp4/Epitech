/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** look
*/

#include "server.h"

static void init_lo(look_t *lo, map_t *map, int level)
{
    lo->visionSize = (level * 2) + 1;
    lo->totalTiles = lo->visionSize * lo->visionSize;
    lo->max_items = 7;

    lo->tiles = (char **)malloc(sizeof(char *) * lo->totalTiles);
    for (int i = 0; i < lo->totalTiles; i++) {
        lo->tiles[i] = NULL;
    }

    lo->current = map;
}

static void next_lo_loop(look_t *lo)
{
    if (lo->current->mendiane > 0)
        strcat(lo->tileString, " mendiane");
    if (lo->current->phiras > 0)
        strcat(lo->tileString, " phiras");
    if (lo->current->thystame > 0)
        strcat(lo->tileString, " thystame");
}

static void lo_loop(look_t *lo, map_t *map, int level)
{
    if (lo->tileX >= map->x - level && lo->tileX <= map->x + level &&
        lo->tileY >= map->y - level && lo->tileY <= map->y + level) {
        int index = (lo->tileY - (map->y - level)) * lo->visionSize +
        (lo->tileX - (map->x - level));
        lo->tileString = (char *)malloc((lo->max_items * 10 + 2) *
        sizeof(char));
        sprintf(lo->tileString, "%s", "");
        if (lo->current->players != NULL)
            strcat(lo->tileString, " player");
        if (lo->current->food > 0)
            strcat(lo->tileString, " food");
        if (lo->current->linemate > 0)
            strcat(lo->tileString, " linemate");
        if (lo->current->deraumere > 0)
            strcat(lo->tileString, " deraumere");
        if (lo->current->sibur > 0)
            strcat(lo->tileString, " sibur");
        next_lo_loop(lo);
        lo->tiles[index] = lo->tileString;
    }
}

static void set_generator(look_t *lo, map_t *map, int level)
{
    init_lo(lo, map, level);
    while (lo->current != NULL) {
        lo->tileX = lo->current->x;
        lo->tileY = lo->current->y;

        lo_loop(lo, map, level);

        lo->current = lo->current->next;
    }
}

char *generate_looked_string(map_t *map, int level)
{
    look_t *lo = malloc(sizeof(look_t));
    set_generator(lo, map, level);
    char *lookString = (char*)malloc(sizeof(char) * (lo->max_items *
    (lo->totalTiles + 3 + 1)));
    sprintf(lookString, "[");
    for (int i = 0; i < lo->totalTiles; i++) {
        if (lo->tiles[i] != NULL) {
            strcat(lookString, lo->tiles[i]);
        }
        strcat(lookString, ",");
    }
    strcat(lookString, " ]");
    for (int i = 0; i < lo->totalTiles; i++) {
        if (lo->tiles[i] != NULL) {
            free(lo->tiles[i]);
        }
    }
    free(lo->tiles);
    free(lo);
    return lookString;
}
