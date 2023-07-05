/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** subscribe.c
*/

#include "client.h"

void subscribe_cmd(PARAMS_CMDS_UNUSED)
{
    printf("/subscribe [\"team_uuid\"] : ");
    printf("subscribe to the event of a team and its sub directories");
    printf(" (enable reception of all events from a team)");

    send_to_server("/subscribe ", buffer, "05 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;
}
