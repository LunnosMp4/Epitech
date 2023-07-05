/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-loic.tisseyre
** File description:
** check_commands.c
*/

#include "myftp.h"

bool check_commands(struct clients_data_t *client,
char *args, bool need[3], int expt)
{
    if (need[1]) {
        if (client->is_logged != true) {
            dprintf(client->fd, "530 Please login with USER and PASS.\r\n");
            return false;
        }
    }
    if (need[0]) {
        if (client->is_passive == false && client->is_active == false) {
            dprintf(client->fd, "425 Use PASV or PORT first.\r\n");
            return false;
        }
    }
    if (!need[2] && expt != 42) {
        if (args[0] != '\r') {
            dprintf(client->fd,
            "501 Syntax error in parameters or arguments.\r\n");
            return false;
        }
    }
    return true;
}
