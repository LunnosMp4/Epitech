/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myftp-william.andreo
** File description:
** linked_list.c
*/

#include "server.h"

int client_length(clients_t *list)
{
    int n = 0;

    if (!list)
        return n;
    while (list != NULL) {
        n++;
        list = list->next;
    }
    return n;
}

clients_t *add_client_front(clients_t *list, int fd)
{
    clients_t *client = malloc(sizeof(*client));

    if (client == NULL)
        exit(84);
    client->sockfd = fd;
    client->username = NULL;
    uuid_clear(client->uuid);
    client->is_logged = false;
    client->request = malloc(sizeof(request_t));
    client->request->code = 0;
    client->request->args = NULL;
    client->request->nb_args = 0;
    client->request->context = CTX_NULL;

    if (!list)
        client->next = NULL;
    else
        client->next = list;
    return client;
}

void delete_client(clients_t **list, int fd)
{
    clients_t *curr = *list;
    clients_t *prev = NULL;

    if (!(*list))
        return;
    while (curr != NULL && curr->sockfd != fd) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        if (prev == NULL)
            *list = curr->next;
        else
            prev->next = curr->next;
        free(curr);
    }
}
