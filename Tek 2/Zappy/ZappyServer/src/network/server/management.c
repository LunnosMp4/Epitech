/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** management
*/

#include "server.h"

static void read_accepted(server_t *server, clients_t *current)
{
    char buffer[100];
    memset(buffer, '\0', 100);
    int nbytes = recv(current->sockfd, buffer, sizeof(buffer), 0);
    if (nbytes == -1) {
        perror("recv() failed");
        return;
    } else if (nbytes == 0) {
        shutdown(current->sockfd, SHUT_RDWR);
        close(current->sockfd);
    } else {
        handle_connection(server, buffer);
    }
}

void client_management(server_t *server, fd_set *readfds)
{
    clients_t *current = server->clients;

    while (current != NULL) {
        if (FD_ISSET(current->sockfd, readfds)) {
            read_accepted(server, current);
        }
        current = current->next;
    }
}

void ret_management(server_t *server, int sockfd, fd_set *readfds)
{
    if (FD_ISSET(sockfd, readfds)) {
        char *name_buffer = malloc(sizeof(char) * 100);
        memset(name_buffer, '\0', 100);
        server->clients = add_client_front(server, server->clients,
        accept_connection(sockfd), &name_buffer);
        if ( server->clients == NULL)
            return;
        clients_t *current = server->clients;
        ai_or_gui_actions(&server, &current, name_buffer);
        free(name_buffer);
    } else {
        client_management(server, readfds);
    }
}
