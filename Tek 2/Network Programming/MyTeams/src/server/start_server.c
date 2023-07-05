/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** start_server.c
*/

#include "server.h"

static int create_socket (void)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed\n");
        exit(84);
    }
    return sockfd;
}

static void bind_socket(int sockfd, int port)
{
    struct sockaddr_in address;
    int optval = 1;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
    &optval, sizeof(optval));
    if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind() failed");
        exit(84);
    }
}

static void sig_handler(int signo)
{
    if (signo == SIGINT)
        exit(0);
}

void start_server(int port)
{
    int sockfd = create_socket();
    server_t *server = init_server(port, sockfd);
    bind_socket(sockfd, port);
    listen_for_connections(sockfd);
    signal(SIGINT, sig_handler);
    while (1) {
        fd_set readfds;
        FD_ZERO(&readfds);
        client_set(server->clients, &readfds);
        FD_SET(sockfd, &readfds);
        select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
        if (FD_ISSET(sockfd, &readfds) > 0)
            server->clients = add_client_front(server->clients,
            accept_connection(sockfd));
        handle_connection(server, &readfds);
    }
    if (shutdown(sockfd, SHUT_RDWR) < 0) {
        perror("shutdown failed");
        exit(84);
    }
}
