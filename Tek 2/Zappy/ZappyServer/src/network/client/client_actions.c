/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** client_list.c
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

clients_t *add_client_front(server_t *s, clients_t *list, int fd, char **n)
{
    clients_t *client = malloc(sizeof(*client));
    client->sockfd = fd;
    client->inv = NULL;
    init_inventory(&client->inv);
    client->lv = 1;
    client->orientation = rand() % 4 + 1;
    client->name_team = NULL;
    client->is_dead = false;
    memset(&client->born_timer, 0, sizeof(struct timeval));
    dprintf(fd, "WELCOME\n");
    while (strcmp(*n, "GRAPHIC\n") != 0 && strcmp(*n, "GRAPHIC\r\n") != 0 &&
    strcmp(*n, "GRAPHIC") != 0 && is_good_name_team(s->nameX, *n) == -1) {
        recv(fd, *n, 100, 0);
    }
    ai_or_gui(s, &client, n, fd);
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

void client_set(clients_t *list_client, fd_set *readfds)
{
    clients_t *client = list_client;

    for (; client; client = client->next)
        FD_SET(client->sockfd, readfds);
}

void clear_request(request_t *request)
{
    request->code = 0;
    request->nb_args = 0;
}
