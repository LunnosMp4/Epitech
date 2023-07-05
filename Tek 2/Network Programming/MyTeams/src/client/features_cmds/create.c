/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** create.c
*/

#include "client.h"

static void team_created(client_t *client)
{
    client_event_team_created(client->response->args[0],
        client->response->args[1], client->response->args[2]);
}

static void channel_created(client_t *client)
{
    client_event_channel_created(client->response->args[0],
        client->response->args[1], client->response->args[2]);
}

static void thread_created(client_t *client)
{
    char uuid_client[37];
    uuid_unparse(client->uuid, uuid_client);
    client_event_thread_created(client->response->args[0],
        uuid_client, atoi(client->response->args[3]), client->response->args[1],
        client->response->args[2]);
}

static void reply_created(client_t *client)
{
    (void)client;
}

void create_cmd(PARAMS_CMDS)
{
    send_to_server("/create ", buffer, "11 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;
    if (client->response->code == 111) {
        if (strcmp(client->response->message, "Team created") == 0)
            team_created(client);
        if (strcmp(client->response->message, "Channel created") == 0)
            channel_created(client);
        if (strcmp(client->response->message, "Thread created") == 0)
            thread_created(client);
        if (strcmp(client->response->message, "Reply created") == 0)
            reply_created(client);
    }
    if (client->response->code == 211)
        client_error_already_exist();
}
