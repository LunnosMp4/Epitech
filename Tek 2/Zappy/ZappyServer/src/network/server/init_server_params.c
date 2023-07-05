/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** init_server_params
*/

#include "server.h"

void init_basics_params(server_t *server, char **av)
{
    server->port = atoi(av[0]);
    server->width = atoi(av[1]);
    server->height = atoi(av[2]);
    server->clientsNb = atoi(av[3]);
    server->freq = atoi(av[4]);
}
