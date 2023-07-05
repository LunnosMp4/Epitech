/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** connection.c
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
    return new_socket;
}

void handle_connection(server_t *s, char *buffer)
{
    s->client = s->clients;
    for (; s->client; s->client = s->client->next) {
        manage_request(s, buffer);
    }
}

void manage_request(server_t *s, char *buffer)
{
    char *new = strcmp(buffer, "\n") != 0 ? strdup(buffer) : strdup("fake");
    parse_request(s, new);
    if (check_request(s) == true) {
        commands[s->client->request->code - 1](s);
    }

    if (check_request_gui(s) == true) {
        gui_commands[s->client->request->code - 1](s, s->client);
    }
    memset(buffer, '\0', 100);
    free(new);
    for (int i = 0; s->client->request->args[i] != NULL; i++)
        free(s->client->request->args[i]);
    free(s->client->request);
}
