/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** list.c
*/

#include "client.h"

void list_cmd(PARAMS_CMDS_UNUSED)
{
    printf("/list : based on what is being used");
    printf(" list all the sub resources (IN PDF)\n");

    send_to_server("/list ", buffer, "13 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;
}
