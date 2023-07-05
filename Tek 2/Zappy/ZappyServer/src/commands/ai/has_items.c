/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** has_items
*/

#include "server.h"

int has_item_set(clients_t *player, commands_order_t *args)
{
    if (strcmp(args->args[0], "linemate") == 0 && player->inv->linemate != 0)
        return 0;
    if (strcmp(args->args[0], "deraumere") == 0 && player->inv->deraumere != 0)
        return 1;
    if (strcmp(args->args[0], "sibur") == 0 && player->inv->sibur != 0)
        return 2;
    if (strcmp(args->args[0], "mendiane") == 0 && player->inv->mendiane != 0)
        return 3;
    if (strcmp(args->args[0], "phiras") == 0 && player->inv->phiras != 0)
        return 4;
    if (strcmp(args->args[0], "thystame") == 0 && player->inv->thystame != 0)
        return 5;
    if (strcmp(args->args[0], "food") == 0 && player->inv->food != 0)
        return 6;
    return -1;
}

int has_item_take(map_t *current_map, commands_order_t *args)
{
    if (strcmp(args->args[0], "linemate") == 0 && current_map->linemate != 0)
        return 0;
    if (strcmp(args->args[0], "deraumere") == 0 && current_map->deraumere != 0)
        return 1;
    if (strcmp(args->args[0], "sibur") == 0 && current_map->sibur != 0)
        return 2;
    if (strcmp(args->args[0], "mendiane") == 0 && current_map->mendiane != 0)
        return 3;
    if (strcmp(args->args[0], "phiras") == 0 && current_map->phiras != 0)
        return 4;
    if (strcmp(args->args[0], "thystame") == 0 && current_map->thystame != 0)
        return 5;
    if (strcmp(args->args[0], "food") == 0 && current_map->food != 0)
        return 6;
    return -1;
}
