/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** users.c
*/

#include "client.h"

void users_cmd(PARAMS_CMDS_UNUSED)
{
    send_to_server("/users ", buffer, "10 BWA ", client);
    int response_id = wait_response(client);
    if (response_id == UNAUTHORIZED)
        client_error_unauthorized();
    if (response_id == ERROR || response_id == UNAUTHORIZED)
        return;
}
