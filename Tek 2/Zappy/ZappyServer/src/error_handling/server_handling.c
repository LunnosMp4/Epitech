/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** server_handling
*/

#include "server.h"

bool check_request(server_t *s)
{
    s->client->request->code = which_command(s->client->request->args[0]);
    if (s->client->request->code == 84) {
        return false;
    }
    return true;
}

int if_can_run_serv(char **av, int ac)
{
    char **args = NULL;
    if ((args = check_args(av, ac, 4269, 10)) != NULL) {
        start_server(args);
        free(args);
        return 0;
    }
    return 84;
}
