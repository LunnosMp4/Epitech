/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-loic.tisseyre
** File description:
** bonus.c
*/

#include "myftp.h"

bool cmd_rmd(struct clients_data_t *client, char *args)
{
    if (!check_commands(client, args, (bool[]){false, true, true}, 0))
        return false;

    args[strlen(args) - 2] = '\0';
    if (rmdir(args) == -1) {
        dprintf(client->fd, "550 Failed to remove directory.\r\n");
        return false;
    }

    dprintf(client->fd, "250 Directory successfully removed.\r\n");
    return true;
}

bool cmd_mkd(struct clients_data_t *client, char *args)
{
    if (!check_commands(client, args, (bool[]){true, true, true}, 0))
        return false;

    args[strlen(args) - 2] = '\0';
    if (mkdir(args, 0777) == -1) {
        dprintf(client->fd, "550 Failed to create directory.\r\n");
        return false;
    }

    dprintf(client->fd, "250 Directory successfully created.\r\n");
    return true;
}
