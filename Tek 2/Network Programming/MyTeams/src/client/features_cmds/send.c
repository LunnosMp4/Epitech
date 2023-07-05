/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** send.c
*/

#include "client.h"

void send_cmd(PARAMS_CMDS_UNUSED)
{
    printf("/send [\"user_uuid\"] [\"message_body\"] :");
    printf(" send a message to a user\n");

    send_to_server("/send ", buffer, "04 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;
}
