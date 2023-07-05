/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** send_to_gui
*/

#include "server.h"

void send_to_gui(server_t *server, clients_t *current)
{
    gui_commands[0](server, current);
    gui_commands[1](server, current);
    gui_commands[2](server, current);
    gui_commands[3](server, current);
}

map_t *find_which_tile(map_t *map_list, int x, int y)
{
    map_t *current = map_list;

    while (current != NULL) {
        if (current->x == x && current->y == y) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void find_which_map(server_t **server, int x, int y)
{
    server_t *current = (*server);
    while (current->tiles != NULL) {
        if (current->tiles->x == x && current->tiles->y == y
        && current->tiles->players == NULL) {
            current->tiles->players = strdup("player");
            return;
        }
        current->tiles = current->tiles->next;
    }
}

void random_pos(server_t **server, clients_t **current)
{
    int x = 0;
    int y = 0;
    while ((*server)->tiles->players == NULL) {
        x = rand() % ((*server)->width - 1);
        y = rand() % ((*server)->height - 1);
        find_which_map(server, x, y);
    }
    (*current)->x = x;
    (*current)->y = y;
}
