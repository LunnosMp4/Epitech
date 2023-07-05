/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** drop
*/

#include "server.h"

static void drop_item2(clients_t **player, map_t **current_map, int opt)
{
    if (opt == 3 && (*player)->inv->mendiane != 0) {
        (*player)->inv->mendiane--;
        (*current_map)->mendiane++;
        return;
    }
    if (opt == 4 && (*player)->inv->phiras != 0) {
        (*player)->inv->phiras--;
        (*current_map)->phiras++;
        return;
    }
    if (opt == 5 && (*player)->inv->thystame != 0) {
        (*player)->inv->thystame--;
        (*current_map)->thystame++;
        return;
    }
    if (opt == 6 && (*player)->inv->food != 0) {
        (*player)->inv->food--;
        (*current_map)->food++;
        return;
    }
}

void drop_item(clients_t **player, map_t **current_map, int opt)
{
    if (opt == 0 && (*player)->inv->linemate != 0) {
        (*player)->inv->linemate--;
        (*current_map)->linemate++;
        return;
    }
    if (opt == 1 && (*player)->inv->deraumere != 0) {
        (*player)->inv->deraumere--;
        (*current_map)->deraumere++;
        return;
    }
    if (opt == 2 && (*player)->inv->sibur != 0) {
        (*player)->inv->sibur--;
        (*current_map)->sibur++;
        return;
    }
    drop_item2(player, current_map, opt);
}

static void take_item2(clients_t **player, map_t **current_map, int opt)
{
    if (opt == 3 && (*player)->inv->mendiane != 0) {
        (*player)->inv->mendiane++;
        (*current_map)->mendiane--;
        return;
    }
    if (opt == 4 && (*player)->inv->phiras != 0) {
        (*player)->inv->phiras++;
        (*current_map)->phiras--;
        return;
    }
    if (opt == 5 && (*player)->inv->thystame != 0) {
        (*player)->inv->thystame++;
        (*current_map)->thystame--;
        return;
    }
    if (opt == 6 && (*player)->inv->food != 0) {
        (*player)->inv->food++;
        (*current_map)->food--;
        return;
    }
}

void take_item(clients_t **player, map_t **current_map, int opt)
{
    if (opt == 0 && (*player)->inv->linemate != 0) {
        (*player)->inv->linemate++;
        (*current_map)->linemate--;
        return;
    }
    if (opt == 1 && (*player)->inv->deraumere != 0) {
        (*player)->inv->deraumere++;
        (*current_map)->deraumere--;
        return;
    }
    if (opt == 2 && (*player)->inv->sibur != 0) {
        (*player)->inv->sibur++;
        (*current_map)->sibur--;
        return;
    }
    take_item2(player, current_map, opt);
}
