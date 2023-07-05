/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** help.c
*/

#include "server.h"

void help(PARAMS_FEATS)
{
    char *help[3] = {
        "/login [\"user_name\"] : set the user_name used by client",
        "/logout : disconnect the client from the server",
        NULL
    };
    dprintf(FD, "114 BWA %s, %s\r\n", help[0], help[1]);
    return;
}
