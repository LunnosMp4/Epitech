/*
** EPITECH PROJECT, 2022
** Bootstrap
** File description:
** Server.c
*/

#include "myftp.h"

/// @brief Create a socket
/// @return The socket
int create_socket(void)
{
    int net_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (net_socket == -1) {
        exit(EXIT_FAILURE);
    }
    return net_socket;
}

/// @brief Bind the socket to the port
/// @param net_socket The socket to bind
/// @param port The port to bind
void bind_socket(int net_socket, int port)
{
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(net_socket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        exit(EXIT_FAILURE);
    }
}

/// @brief Listen to the socket
/// @param net_socket The socket to listen to
void listen_socket(int net_socket)
{
    if (listen(net_socket, QUEUE_LEN) < 0) {
        exit(EXIT_FAILURE);
    }
}

void start_server(int port, char *path)
{
    int net_socket = create_socket();
    bind_socket(net_socket, port);
    listen_socket(net_socket);
    printf("Listening on port %d...\n", port);

    while (1) {
        accept_connection(net_socket, path);
    }
}
