/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
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

static void server_loop(server_t *server, int sockfd)
{
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    fd_set readfds;
    FD_ZERO(&readfds);
    client_set(server->clients, &readfds);
    FD_SET(sockfd, &readfds);
    int ret = select(FD_SETSIZE, &readfds, NULL, NULL, &timeout);
    if (ret == -1) {
        perror("select() failed");
        exit(EXIT_FAILURE);
    }
    if (ret > 0) {
        ret_management(server, sockfd, &readfds);
    }
}

void start_server(char **av)
{
    int sockfd = create_socket();
    server_t *server = init_server(sockfd, av);
    bind_socket(sockfd, server->port);
    listen_for_connections(sockfd);
    signal(SIGINT, sig_handler);
    srand(time(NULL));
    while (1) {
        check_death_players(server, &server->clients, server->freq);
        check_commands_up(server);
        server_loop(server, sockfd);
    }
    if (shutdown(sockfd, SHUT_RDWR) < 0) {
        perror("shutdown failed");
        free_all(server);
        exit(84);
    }
    free_all(server);
}
