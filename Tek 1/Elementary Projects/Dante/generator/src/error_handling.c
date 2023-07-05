/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-enzo.daumalle
** File description:
** error_handling.c
*/

#include "generator.h"

static void check_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            exit(84);
}

static void display_help(void)
{
    printf("Usage:\n    Imperfect Maze :\n\t./generator 'width' 'height'\n\
    Perfect Maze :\n\t./generator 'width' 'height' [perfect]\n");
}

static void error_handling_imperfect(int ac, char **av)
{
    (void) ac;
    check_number(av[1]);
    check_number(av[2]);
}

static void error_handling_perfect(int ac, char **av)
{
    (void) ac;
    check_number(av[1]);
    check_number(av[2]);
    if (strcmp(av[3], "perfect") != 0)
        exit(84);
}

void error_handling(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        display_help();
    if (ac == 3)
        error_handling_imperfect(ac, av);
    else if (ac == 4)
        error_handling_perfect(ac, av);
    else
        exit(84);
}
