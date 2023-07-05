/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** connection_manager.c
*/

#include "server.h"

void listen_for_connections(int sockfd)
{
    if (listen(sockfd, 5) < 0) {
        perror("listen() failed");
        exit(84);
    }
}

int accept_connection(int sockfd)
{
    struct sockaddr_in address;
    int addresslen = sizeof(address);
    int new_socket = accept(sockfd, (struct sockaddr*)&address,
    (socklen_t*)&addresslen);

    if (new_socket < 0) {
        perror("accept() failed");
        exit(84);
    }
    dprintf(new_socket, "100 BWA Service ready for new user\r\n");
    return new_socket;
}

void handle_connection(server_t *s, fd_set *readfds)
{
    char buffer[BUFSIZ];
    s->client = s->clients;

    for (; s->client; s->client = s->client->next) {
        memset(buffer, '\0', BUFSIZ);
        if (FD_ISSET(s->client->sockfd, readfds) > 0)
            wait_request(buffer, s);
    }
}

void client_set(clients_t *list_client, fd_set *readfds)
{
    clients_t *client = list_client;

    for (; client; client = client->next)
        FD_SET(client->sockfd, readfds);
}
