/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** use.c
*/

#include "client.h"

void use_cmd(PARAMS_CMDS_UNUSED)
{
    send_to_server("/use ", buffer, "08 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;

    if (client->response->code == 208) {
        if (strcmp(client->response->message, "Unknow Team") == 0) {
            client_error_unknown_team(client->response->args[0]);
        }
        if (strcmp(client->response->message, "Unknow Channel") == 0) {
            client_error_unknown_channel(client->response->args[0]);
        }
        if (strcmp(client->response->message, "Unknow Thread") == 0) {
            client_error_unknown_thread(client->response->args[0]);
        }
    }
}
