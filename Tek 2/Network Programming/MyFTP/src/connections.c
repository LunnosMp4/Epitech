/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-loic.tisseyre
** File description:
** connections.c
*/

#include "commands.h"

/// @brief Execute a command
/// @param i Index of the command
/// @param args Argument(s) of the command
/// @param client_socket Know socket of the client
/// @param clients Array of clients structure
void exec_command(int i, char *args, int client_socket,
struct clients_data_t *clients)
{
    while (*args && (*args == ' ' || *args == '\t')) {
        args++;
    }

    int socket_id = 0;
    for (; socket_id < MAX_CLIENTS; socket_id++) {
        if (clients[socket_id].fd == client_socket) {
            break;
        }
    }

    commands[i].func(&clients[socket_id], args);
    args = NULL;
}

/// @brief Detect if the input contain a command
/// @param buffer Input string
/// @param client_socket Know socket of the client
/// @param clients Array of clients structure
void check_buffer(char *buffer, int client_socket,
struct clients_data_t *clients)
{
    bool is_exec = false;
    for (int i = 0; commands[i].name != NULL; i++) {

        int len = strlen(commands[i].name);
        if (strncmp(buffer, commands[i].name, len) == 0) {
            char *args = buffer + len;
            exec_command(i, args, client_socket, clients);
            is_exec = true;
            break;
        }
    }
    if (is_exec == false)
        send(client_socket,
        "500 Command not implemented. \
The server does not support this command.\r\n", 72, 0);
}

/// @brief Handle the commands
/// @param client_socket The socket of the client
/// @param commands Array of clients structure
void handle_commands(int client_socket, struct clients_data_t *clients)
{
    char buffer[BUF_SIZE];
    int read_size;

    while ((read_size = read(client_socket, buffer, BUF_SIZE)) > 0) {
        if (read_size > BUF_SIZE) {
            read_size = BUF_SIZE;
        }
        buffer[read_size] = '\0';
        check_buffer(buffer, client_socket, clients);
        memset(buffer, 0, BUF_SIZE);
    }
}

void init_client(int client_socket, char *path)
{
    dprintf(client_socket, "220 Service ready for new user.\r\n");
    struct clients_data_t *clients = malloc(sizeof(struct clients_data_t));
    if (clients == NULL) {
        exit(EXIT_FAILURE);
    }
    clients->fd = client_socket;
    clients->data_fd = -1;
    clients->username = NULL;
    clients->is_logged = false;
    clients->is_passive = false;
    clients->is_active = false;
    clients->anonymous_path = path;
    clients->current_path = NULL;

    handle_commands(client_socket, clients);
    close(client_socket);
    free(clients);
    exit(EXIT_SUCCESS);
}

/// @brief Accept a connection from any socket
/// @param net_socket The socket of the server
void accept_connection(int net_socket, char *path)
{
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_socket = accept(net_socket, (struct sockaddr *)
    &client_address, &client_address_len);
    if (client_socket == -1) {
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
        init_client(client_socket, path);
    else
        close(client_socket);
}
