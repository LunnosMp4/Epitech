/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** logout.c
*/

#include "client.h"

void logout_cmd(PARAMS_CMDS_UNUSED)
{
    send_to_server("/logout ", buffer, "02 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;
    if (client->response->code == 102) {
        char uuid_str[37] = {0};
        uuid_unparse(client->uuid, uuid_str);
        client_event_logged_out(uuid_str, client->username);
        client->username = NULL;
        uuid_clear(client->uuid);
    }
}
