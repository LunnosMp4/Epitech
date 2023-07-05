/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** gui_select
*/

#include "server.h"

static int which_gui_command(char *user_command)
{
    if (strcmp(user_command, "pin") == 0)
        return 9;

    if (strcmp(user_command, "plv") == 0)
        return 5;

    if (strcmp(user_command, "sst") == 0)
        return 7;

    return 84;
}

bool check_request_gui(server_t *s)
{
    s->client->request->code = which_gui_command(s->client->request->args[0]);
    if (s->client->request->code == 84) {
        return false;
    }
    return true;
}
