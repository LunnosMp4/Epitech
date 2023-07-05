/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-loic.tisseyre
** File description:
** mode.c
*/

#include "myftp.h"

static void print_pasv_mode(struct clients_data_t *client,
struct sockaddr_in data_socket_address)
{
    dprintf(client->fd, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d).\r\n",\
    (ntohl(data_socket_address.sin_addr.s_addr) >> 24) & 0xFF, \
    (ntohl(data_socket_address.sin_addr.s_addr) >> 16) & 0xFF, \
    (ntohl(data_socket_address.sin_addr.s_addr) >> 8) & 0xFF, \
    ntohl(data_socket_address.sin_addr.s_addr) & 0xFF, \
    client->data_port >> 8, \
    client->data_port & 0xFF);
}

static bool listen_to_client(struct clients_data_t *client,
struct sockaddr_in data_socket_address, socklen_t data_socket_address_len)
{
    data_socket_address.sin_family = AF_INET;
    data_socket_address.sin_port = htons(0);
    data_socket_address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(client->data_fd, (struct sockaddr *)
    &data_socket_address, data_socket_address_len) < 0) {
        close(client->data_fd);
        return false;
    }
    if (listen(client->data_fd, 1) < 0) {
        close(client->data_fd);
        return false;
    }
    if (getsockname(client->data_fd, (struct sockaddr *)
    &data_socket_address, &data_socket_address_len) < 0) {
        close(client->data_fd);
        return false;
    }
    client->data_port = ntohs(data_socket_address.sin_port);
    return true;
}

bool passive_mode(struct clients_data_t *client, UNUSED char *args)
{
    if (!check_commands(client, args, (bool[]){false, true, false}, 0))
        return false;
    struct sockaddr_in data_socket_address;
    socklen_t data_socket_address_len = sizeof(data_socket_address);
    if ((client->data_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return false;
    }
    memset(&data_socket_address, 0, data_socket_address_len);
    if (listen_to_client(client, data_socket_address,
    data_socket_address_len) == false)
        return false;
    print_pasv_mode(client, data_socket_address);
    client->is_passive = true;
    client->is_active = false;
    return true;
}

bool active_mode(struct clients_data_t *client, UNUSED char *args)
{
    if (!check_commands(client, args, (bool[]){false, true, true}, 0))
        return false;
    client->is_passive = false;
    if (client->is_active == true) {
        close(client->data_port);
        client->is_active = false;
    }
    client->is_active = true;
    dprintf(client->fd, "200 Active mode.\r\n");
    return true;
}
