/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** setup_connection.c
*/

#include "client.h"

static void setup_connection(client_t *client)
{
    client->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->fd == -1) {
        printf("Socket creation error \n");
        exit(84);
    }

    client->serv_addr.sin_family = AF_INET;
    client->serv_addr.sin_port = htons(client->port);

    if (inet_pton(AF_INET, client->ip, &client->serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported \n");
        exit(84);
    }

    if (connect(client->fd, (struct sockaddr*) &client->serv_addr,
        sizeof(client->serv_addr)) < 0) {
        printf("Connection Failed \n");
        exit(84);
    }
}

static void sig_handler(int signo)
{
    if (signo == SIGINT) {
        exit(0);
    }
}

void connection(client_t *client)
{
    char buffer[MAX_BUFFER_SIZE] = {0};

    setup_connection(client);
    wait_response(client);
    signal(SIGINT, sig_handler);
    while (read(0, buffer, MAX_BUFFER_SIZE) > 0) {
        builtin_t *cmd = get_builtin(buffer);
        if (!cmd) {
            memset(buffer, 0, MAX_BUFFER_SIZE);
            continue;
        }
        cmd->fptr(client, buffer);
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }
    close(client->fd);
    free(client);
}
