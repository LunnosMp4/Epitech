/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** check_args.c
*/

#include "client.h"

static void check_ip(char *ip)
{
    int count = 0;

    for (int i = 0; ip[i] != '\0'; i++) {
        if (ip[i] == '.')
            count++;
        if (ip[i] != '.' && (ip[i] < '0' || ip[i] > '9')) {
            printf("Invalid IP address.\n");
            exit(84);
        }
    }
    if (count != 3) {
        printf("Invalid IP address.\n");
        exit(84);
    }
}

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
    if (ac != 3) {
        printf("Invalid number of arguments.\n");
        exit(84);
    }
    check_ip(av[1]);
    check_port(av[2]);
}
