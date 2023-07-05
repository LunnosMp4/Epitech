/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** init_server.c
*/

#include "server.h"

static int *init_resources_value(int w, int h)
{
    int *array = malloc(sizeof(int) * 7);

    array[0] = (int)round((w * h) * 0.5);
    array[1] = (int)round((w * h) * 0.3);
    array[2] = (int)round((w * h) * 0.15);
    array[3] = (int)round((w * h) * 0.1);
    array[4] = (int)round((w * h) * 0.1);
    array[5] = (int)round((w * h) * 0.08);
    array[6] = (int)round((w * h) * 0.05);
    return array;
}

static char **init_team_names(server_t *server, char **args, int *max_teams)
{
    int max = 0;
    for (int i = 5; args[i] != NULL; max++, i++);
    char **nameX = (char **)malloc(sizeof(char*) * (max + 1));

    for (int j = 0; j != max; j++) {
        nameX[j] = NULL;
        nameX[j + 1] = NULL;
    }
    for (int i = 5, j = 0; j != max; i++, j++) {
        if (is_in_array(nameX, args[i])) {
            free_all(server);
            exit(84);
        }
        nameX[j] = strdup(args[i]);
    }
    *max_teams = max;
    return nameX;
}

server_t *init_server(int sockfd, char **av)
{
    server_t *server = malloc(sizeof(server_t));
    int max_teams = 0;
    server->clients = NULL;
    server->client = NULL;
    init_basics_params(server, av);
    server->nameX = init_team_names(server, av, &max_teams);
    server->players_in_teams = init_teams(max_teams);
    server->sockfd = sockfd;
    server->tiles = NULL;
    server->next_number = 1;
    for (int y = 0; y != server->height; y++) {
        for (int x = 0; x != server->width; x++)
            init_map(&server->tiles, x, y);
    }
    server->resources_data =
    init_resources_value(server->width, server->height);
    server->tiles = setup_resources_in_map(server->tiles,
    server->resources_data, server->width, server->height);
    server->cmd = NULL;
    return server;
}
