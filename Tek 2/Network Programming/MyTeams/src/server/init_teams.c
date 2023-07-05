/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** init_teams.c
*/

#include "server.h"

server_t *init_server(int port, int sockfd)
{
    server_t *server = malloc(sizeof(server_t));

    if (!server)
        return NULL;
    server->clients = NULL;
    server->client = NULL;
    server->channels = NULL;
    server->comments = NULL;
    server->teams = NULL;
    server->threads = NULL;
    server->messages = NULL;
    server->subscriptions = NULL;
    server->teams = NULL;
    server->port = port;
    server->sockfd = sockfd;
    return server;
}
