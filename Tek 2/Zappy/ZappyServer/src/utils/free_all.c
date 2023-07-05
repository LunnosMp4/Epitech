/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** free_all
*/

#include "server.h"

char **free_new_args(char **new_args, char **new_new_args)
{
    for (int a = 0; new_args[a] != NULL; a++)
        free(new_args[a]);
    free(new_args);
    return new_new_args;
}

void free_linked_list(map_t **list)
{
    map_t *current = *list;
    while (current != NULL) {
        map_t *temp = current;
        current = current->next;
        free(temp->players);
        free(temp);
    }
    *list = NULL;
}

void free_all(server_t *server)
{
    for (int i = 0; server->nameX[i] != NULL; i++) {
        free(server->nameX[i]);
    }

    free(server->nameX);
    free_linked_list(&server->tiles);
    free(server->resources_data);
    free(server->clients->request);
    free(server->clients);
    free(server);
}
