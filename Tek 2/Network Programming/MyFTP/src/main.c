/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-loic.tisseyre
** File description:
** main.c
*/

#include "myftp.h"

/// @brief Show the help
/// @param av Arguments
void show_help(char **av)
{
    if (strcmp(av[1], "-help") == 0 || strcmp(av[1], "-h") == 0) {
        printf("USAGE: ./myftp port path\n");
        printf("\tport\tis the port number on which \
the server socket listens\n");
        printf("\tpath\tis the path to the home directory \
for the Anonymous user\n");
        exit(0);
    } else {
        fprintf(stderr, "Invalid argument\n");
        exit(84);
    }
}

/// @brief Check the arguments
/// @param ac Number of arguments
/// @param av Arguments
void check_args(int ac, char **av)
{
    if (ac == 2)
        show_help(av);
    if (ac != 3) {
        fprintf(stderr, "Invalid number of arguments\n");
        exit(84);
    }

    for (int i = 0; av[1][i] != '\0'; i++) {
        if (isdigit(av[1][i]) == 0) {
            fprintf(stderr, "Invalid port number\n");
            exit(84);
        }
    }

    if (access(av[2], F_OK) == -1) {
        fprintf(stderr, "Invalid path\n");
        exit(84);
    }
}

int main(int ac, char **av)
{
    check_args(ac, av);
    start_server(atoi(av[1]), av[2]);
    return 0;
}
