/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-loic.tisseyre
** File description:
** files_actions.c
*/

#include "myftp.h"

static bool print_list(struct clients_data_t *client)
{
    char buffer[4096];
    FILE *file;
    file = popen("ls -l", "r");
    while (fgets(buffer, 4096, file))
        dprintf(client->fd, "%s", buffer);
    pclose(file);
    if (client->is_passive == true)
        dprintf(client->fd, "150 Here comes the directory listing.\r\n");
    if (client->is_active == true)
        dprintf(client->fd, "226 Directory send OK.\r\n");
    return true;
}

bool cmd_list(struct clients_data_t *client, char *args)
{
    if (!check_commands(client, args, (bool[]){true, true, true}, 42))
        return false;
    args[strlen(args) - 2] = '\0';
    if (args[0] != '\0') {
        if (chdir(args) == -1) {
            dprintf(client->fd, "550 Failed to list directory.\r\n");
            return false;
        } else {
            return print_list(client);
        }
    }
    print_list(client);
    return true;
}

bool write_file(struct clients_data_t *client, char *args, int fd)
{
    int file = open(args, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (file == -1) {
        dprintf(client->fd, "550 Failed to open file.\r\n");
        return false;
    }
    dprintf(client->fd, "150 Opening BINARY mode data connection\r\n");
    char buffer[4096];
    int size = 0;
    while ((size = read(fd, buffer, 4096)) > 0) {
        write(file, buffer, size);
    }
    dprintf(client->fd, "226 Transfer complete.\r\n");
    close(file);
    return true;
}

bool cmd_retr(struct clients_data_t *client, char *args)
{
    if (!check_commands(client, args, (bool[]){true, true, true}, 0))
        return false;
    args[strlen(args) - 2] = '\0';
    int fd = client->data_fd;
    if (write_file(client, args, fd) == false)
        return false;
    return true;
}

bool cmd_stor(struct clients_data_t *client, char *args)
{
    if (!check_commands(client, args, (bool[]){true, true, true}, 0))
        return false;
    args[strlen(args) - 2] = '\0';
    int fd = client->data_fd;
    if (write_file(client, args, fd) == false)
        return false;
    return true;
}
