/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** help.c
*/

#include "client.h"

void help_cmd(PARAMS_CMDS_UNUSED)
{
    send_to_server("/help ", buffer, "14 BWA ", client);
    wait_response(client);
}
