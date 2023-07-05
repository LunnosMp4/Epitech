/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** info.c
*/

#include "client.h"

static void info_user(client_t *client)
{
    char uuid_str[37];
    uuid_unparse(client->uuid, uuid_str);
    client_print_user(uuid_str, client->username, 1);
}

static void info_channel(client_t *client)
{
    client_print_channel(client->response->args[0], client->response->args[1],
    client->response->args[2]);
}

static void info_thread(UNUSED client_t *client)
{
    client_print_thread(client->response->args[0], client->response->args[1],
    atoi(client->response->args[2]), client->response->args[3],
    client->response->args[4]);
}

static void info_team(client_t *client)
{
    client_print_team(client->response->args[0], client->response->args[1],
    client->response->args[2]);
}

void info_cmd(PARAMS_CMDS)
{
    send_to_server("/info ", buffer, "12 BWA ", client);

    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;
    if (client->response->code == 112) {
        if (strcmp(client->response->message, "User info") == 0)
            info_user(client);
        if (strcmp(client->response->message, "Channel info") == 0)
            info_channel(client);
        if (strcmp(client->response->message, "Thread info") == 0)
            info_thread(client);
        if (strcmp(client->response->message, "Team info") == 0)
            info_team(client);
    }
}
