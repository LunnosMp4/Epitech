/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** incantation
*/

#include "server.h"

bool test_inventory(clients_t *p, map_t *tile, int max_size)
{
    if (p->lv == 4 && max_size >= 4 && tile->linemate >= 1 &&
    tile->deraumere >= 1 && tile->sibur >= 2 && tile->mendiane >= 0 &&
    tile->phiras >= 1 && tile->thystame >= 0)
        return true;
    if (p->lv == 5 && max_size >= 4 && tile->linemate >= 1 &&
    tile->deraumere >= 2 && tile->sibur >= 1 && tile->mendiane >= 3 &&
    tile->phiras >= 0 && tile->thystame >= 0)
        return true;
    if (p->lv == 6 && max_size >= 6 && tile->linemate >= 1 &&
    tile->deraumere >= 2 && tile->sibur >= 3 && tile->mendiane >= 0 &&
    tile->phiras >= 1 && tile->thystame >= 0)
        return true;
    if (p->lv == 7 && max_size >= 6 && tile->linemate >= 2 &&
    tile->deraumere >= 2 && tile->sibur >= 2 && tile->mendiane >= 2 &&
    tile->phiras >= 2 && tile->thystame >= 1)
        return true;
    return false;
}

bool can_incantation(server_t *s, clients_t *player, map_t *map)
{
    int team = find_team(s->nameX, player->name_team);
    map_t *tile = find_map(map, player->x, player->y);
    int max_size = s->players_in_teams[team];
    if (player->lv == 1 && max_size >= 1 && tile->linemate >= 1 &&
    tile->deraumere >= 0 && tile->sibur >= 0 &&
    tile->mendiane >= 0 && tile->phiras >= 0 &&
    tile->thystame >= 0)
        return true;
    if (player->lv == 2 && max_size >= 2 && tile->linemate >= 1 &&
    tile->deraumere >= 1 && tile->sibur >= 1 &&
    tile->mendiane >= 0 && tile->phiras >= 0 &&
    tile->thystame >= 0)
        return true;
    if (player->lv == 3 && max_size >= 2 && tile->linemate >= 2 &&
    tile->deraumere >= 0 && tile->sibur >= 1 &&
    tile->mendiane >= 0 && tile->phiras >= 2 &&
    tile->thystame >= 0)
        return true;
    return test_inventory(player, tile, max_size);
}
