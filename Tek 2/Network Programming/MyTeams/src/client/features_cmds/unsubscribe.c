/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** unsubscribe.c
*/

#include "client.h"

void unsubscribe_cmd(PARAMS_CMDS_UNUSED)
{
    printf("/unsubscribe [“team_uuid”] : unsubscribe from a team\n");

    send_to_server("/unsubscribe ", buffer, "06 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;
}
