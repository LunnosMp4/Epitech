/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** login.c
*/

#include "client.h"

void login_cmd(PARAMS_CMDS)
{
    send_to_server("/login ", buffer, "01 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;
    if (client->response->code == 101) {
        client_event_logged_in(client->response->args[0],
        client->response->args[1]);
        uuid_parse(client->response->args[0], client->uuid);
        client->username = strdup(client->response->args[1]);
    }
}
