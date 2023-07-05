/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** main.c
*/

#include "server.h"

static void help_usage(void)
{
    printf("USAGE: ./myteams_server port\n");
    printf("\tport\tis the port number on which the server socket listens\n");
    exit(0);
}

int main(int ac, char **av)
{
    if (ac == 2 && !strcmp(av[1], "-help"))
        help_usage();
    check_args(ac, av);

    printf("Server started on port %s\n", av[PORT]);
    start_server(atoi(av[PORT]));
    return 0;
}
