/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** check_args.c
*/

#include "server.h"

static void check_port(char *port_str)
{
    int port = atoi(port_str);

    if (port < 1 || port > 65535) {
        printf("Invalid port number.\n");
        exit(84);
    }
}

void check_args(int ac, char **av)
{
    if (ac != 2) {
        printf("Invalid number of arguments.\n");
        exit(84);
    }
    check_port(av[1]);
}
