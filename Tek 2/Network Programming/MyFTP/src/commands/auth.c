/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-loic.tisseyre
** File description:
** auth.c
*/

#include "myftp.h"

static bool set_path(struct clients_data_t *client)
{
    if (chdir(client->anonymous_path) == -1) {
        dprintf(client->fd, "550 Failed to change directory.\n");
        return false;
    }

    if (client->current_path != NULL)
        free(client->current_path);
    client->current_path = getcwd(NULL, 0);
    return true;
}

bool auth_username(struct clients_data_t *client, char *username)
{
    if (!check_commands(client, username, (bool[]){false, false, true}, 0))
        return false;

    if (client->username != NULL) {
        free(client->username);
        client->username = NULL;
    }

    client->username = malloc(sizeof(char) * (strlen(username) + 1));
    strcpy(client->username, username);
    dprintf(client->fd,
    "331 User name okay, need password.\r\n");
    return true;
}

bool auth_password(struct clients_data_t *client, char *password)
{
    char *password_real = "\r\n";
    if (!check_commands(client, password, (bool[]){false, false, true}, 42))
        return false;
    if (strcmp(client->username, "Anonymous\r\n") != 0) {
        dprintf(client->fd, "530 Login incorrect.\r\n");
        return false;
    }
    if (strcmp(password, password_real) != 0) {
        dprintf(client->fd, "530 Login incorrect.\r\n");
        return false;
    }
    client->is_logged = true;
    if (set_path(client) == false)
        return false;
    dprintf(client->fd, "230 Login successful.\r\n");
    return true;
}

bool quit(struct clients_data_t *client, UNUSED char *args)
{
    if (!check_commands(client, args, (bool[]){false, false, false}, 0))
        return false;
    if (client->current_path != NULL)
        free(client->current_path);
    dprintf(client->fd,
    "221 Service closing control connection.\r\n");
    close(client->fd);
    return true;
}
