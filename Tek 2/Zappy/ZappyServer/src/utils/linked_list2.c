/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** linked_list2
*/

#include "server.h"

void remove_command2(commands_order_t **current, commands_order_t **prev,
commands_order_t **list)
{
    if ((*prev) == NULL) {
        *list = (*current)->next;
    } else {
        (*prev)->next = (*current)->next;
    }
    for (int i = 0; (*current)->args[i] != NULL; i++)
        free((*current)->args[i]);
    free((*current)->args);
    free((*current)->command);
}

clients_t *find_id(clients_t *client, int id)
{
    clients_t *current = client;

    for (; current != NULL; current = current->next) {
        if (current->number == id)
            return current;
    }
    return NULL;
}

map_t *find_map(map_t *tiles, int x, int y)
{
    map_t *current = tiles;

    for (; current != NULL; current = current->next) {
        if (current->x == x && current->y == y)
            return current;
    }
    return NULL;
}
