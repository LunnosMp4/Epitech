/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** error_handling.c
*/

#include "my.h"

int error_handling(int ac, char **av)
{
    if (ac != 2)
        return -1;
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("     ./my_sokoban map\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("     map file representing the warehouse map, containing ");
        my_putstr("'#' for walls,\n");
        my_putstr("         'P' for the player, 'X' for boxesand 'O' for ");
        my_putstr("storage locations.\n");
    }
    return 0;
}

void check_number_of_elements(int x_check, int o_check)
{
    char *error2 = "error: Missing Boxe or Storage.\n";
    char *error3 = "error: No Boxe Found.\n";
    char *error4 = "error: No Storage Found.\n";

    if (x_check == 0) {
        write(2, error3, my_strlen(error3));
        exit(84);
    }

    if (o_check == 0) {
        write(2, error4, my_strlen(error4));
        exit(84);
    }
    if (o_check != x_check) {
        write(2, error2, my_strlen(error2));
        exit(84);
    }
}

void check_player(char *buffer)
{
    int p_check = 0;
    char *error = "error: No Player Found.\n";
    char *error2 = "error: Too many Players.\n";

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'P') {
            p_check++;
        }
    }
    if (p_check == 0) {
        write(2, error, my_strlen(error));
        exit(84);
    }
    if (p_check > 1) {
        write(2, error2, my_strlen(error2));
        exit(84);
    }
}

void check_invalid_map(char *buffer)
{
    char *error = "error: Invalid Character in Map.\n";
    int x_check = 0;
    int o_check = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != 'X' && buffer[i] != '#' && buffer[i] != 'P' &&
        buffer[i] != 'O' && buffer[i] != '\n' && buffer[i] != ' ') {
            write(2, error, my_strlen(error));
            exit(84);
        }
        if (buffer[i] == 'X') {
            x_check++;
        }
        if (buffer[i] == 'O') {
            o_check++;
        }
    }
    check_player(buffer);
    check_number_of_elements(x_check, o_check);
}
