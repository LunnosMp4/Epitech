/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** linked_list
*/

#include "server.h"

clients_t *find_item(clients_t *list, int fd)
{
    clients_t *current = list;

    while (current != NULL) {
        if (current->sockfd == fd) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void remove_command(commands_order_t **list, char *to_find, int fd)
{
    if (*list == NULL)
        return;
    commands_order_t *current = *list;
    commands_order_t *prev = NULL;
    while (current != NULL) {
        if (current->fd == fd && strcmp(current->command, to_find) == 0) {
            remove_command2(&current, &prev, list);
            break;
        }
        prev = current;
        current = current->next;
    }
}

void add_cmd(commands_order_t **l, char *c, char **args,
int fd, struct timeval a, double g)
{
    commands_order_t *new_command = malloc(sizeof(commands_order_t));
    new_command->command = strdup(c);
    new_command->args = copy_double_array(args, 1);
    new_command->fd = fd;
    new_command->asked_timer = a;
    new_command->good_time = g;
    new_command->next = NULL;

    if (*l == NULL) {
        *l = new_command;
    } else {
        commands_order_t *current = *l;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_command;
    }
}

void init_map(map_t **list, int x, int y)
{
    map_t *newItem = (map_t*)malloc(sizeof(map_t));
    newItem->players = NULL;
    newItem->x = x;
    newItem->y = y;
    newItem->food = 0;
    newItem->linemate = 0;
    newItem->deraumere = 0;
    newItem->sibur = 0;
    newItem->mendiane = 0;
    newItem->phiras = 0;
    newItem->thystame = 0;
    newItem->next = NULL;
    if (*list == NULL) {
        *list = newItem;
    } else {
        map_t *current = *list;
        while (current->next != NULL)
            current = current->next;
        current->next = newItem;
    }
}

void print_linked_map(map_t *tiles)
{
    map_t *current = tiles;
    while (current != NULL) {
        printf("X: %d, Y: %d, Food: %d, Linemate: %d, Deraumere: \
%d, Sibur: %d, Mendiane: %d, Phiras: %d, Thystame: %d\n",
        current->x, current->y, current->food,
        current->linemate, current->deraumere, current->sibur,
        current->mendiane, current->phiras, current->thystame);
        current = current->next;
    }
}
