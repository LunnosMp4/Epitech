/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** messages.c
*/

#include "client.h"

void messages_cmd(PARAMS_CMDS_UNUSED)
{
    printf("/messages [“user_uuid”] : list all messages");
    printf(" exchange with an user\n");
    send_to_server("/messages ", buffer, "05 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;
}
