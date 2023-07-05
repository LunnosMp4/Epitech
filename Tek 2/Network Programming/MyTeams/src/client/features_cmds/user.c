/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** user.c
*/

#include "client.h"

void user_cmd(PARAMS_CMDS_UNUSED)
{
    printf("/user [\"user_uuid\"] : get information about a user");
    send_to_server("/user ", buffer, "09 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;

    if (client->response->code == 109) {
        client_print_user(client->response->args[0], client->response->args[1],
        atoi(client->response->args[2]));
    }
    if (client->response->code == 209) {
        client_error_unknown_user(client->response->args[0]);
    }
}
