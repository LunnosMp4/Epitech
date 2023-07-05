/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-loic.tisseyre
** File description:
** controls.c
*/

#include "myftp.h"

static bool save_current_path(struct clients_data_t *client)
{
    char *path = getcwd(NULL, 0);

    if (client->anonymous_path[strlen(client->anonymous_path) - 1] == '/')
        client->anonymous_path[strlen(client->anonymous_path) - 1] = '\0';

    int res = strncmp(path, client->anonymous_path,
    strlen(client->anonymous_path));
    if (res != 0) {
        dprintf(client->fd, "550 Access denied.\r\n");
        chdir(client->current_path);
        free(path);
        return false;
    }

    if (client->current_path != NULL)
        free(client->current_path);
    client->current_path = getcwd(NULL, 0);
    return true;
}

bool cmd_cwd(struct clients_data_t *client, char *args)
{
    if (!check_commands(client, args, (bool[]){false, true, true}, 0))
        return false;
    args[strlen(args) - 2] = '\0';
    if (args[0] == '/') {
        if (chdir("/") == -1) {
            dprintf(client->fd, "550 Failed to change directory.\r\n");
            return false;
        }
        args++;
    }
    if (chdir(args) == -1) {
        dprintf(client->fd, "550 Failed to change directory.\r\n");
        return false;
    }
    if (save_current_path(client) == false)
        return false;
    dprintf(client->fd, "250 Directory successfully changed.\r\n");
    return true;
}

bool cmd_cdup(struct clients_data_t *client, UNUSED char *args)
{
    if (!check_commands(client, args, (bool[]){false, true, false}, 0))
        return false;
    if (chdir("..") == -1) {
        dprintf(client->fd, "550 Failed to change directory.\r\n");
        return false;
    }
    if (save_current_path(client) == false)
        return false;

    dprintf(client->fd, "200 Command okay.\r\n");
    return true;
}

bool cmd_pwd(struct clients_data_t *client, char *args)
{
    if (!check_commands(client, args, (bool[]){false, true, false}, 0))
        return false;

    dprintf(client->fd, "257 \"%s\" is current directory.\r\n",
    client->current_path);
    return true;
}

bool cmd_dele(struct clients_data_t *client, char *args)
{
    if (!check_commands(client, args, (bool[]){false, true, true}, 0))
        return false;

    args[strlen(args) - 2] = '\0';
    if (remove(args) == -1) {
        dprintf(client->fd, "550 Failed to delete file.\r\n");
        return false;
    }

    dprintf(client->fd, "250 Requested file action okay, completed.\r\n");
    return true;
}
