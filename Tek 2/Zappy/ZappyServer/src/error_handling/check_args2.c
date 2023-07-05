/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** check_args2
*/

#include "server.h"

void check_port(int port)
{
    if (port < 1 || port > 65535) {
        printf("Invalid port number.\n");
        exit(84);
    }
}

void check_map_size(int w, int h)
{
    if (w < 1 || w > 30 || h < 1 || h > 30) {
        printf("Invalid size map.\n");
        exit(84);
    }
}

void check_freq(int freq)
{
    if (freq <= 1) {
        printf("Invalid freq number.\n");
        exit(84);
    }
}

void check_clients_nb(int clt)
{
    if (clt < 1) {
        printf("Invalid clientsNb number.\n");
        exit(84);
    }
}

void check_all(int port, int width, int height, int clientNb)
{
    check_port(port);
    check_map_size(width, height);
    check_clients_nb(clientNb);
}
