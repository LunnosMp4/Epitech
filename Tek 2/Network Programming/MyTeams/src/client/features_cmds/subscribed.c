/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** subscribed.c
*/

#include "client.h"

void subscribed_cmd(PARAMS_CMDS_UNUSED)
{
    printf("/subscribed ?[“team_uuid”] : list all subscribed teams or ");
    printf("list all users subscribed to a team\n");

    send_to_server("/subscribed ", buffer, "07 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;
}
