/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main.c
*/

#include "solver.h"

int main(int ac, char **av)
{

    if (ac != 2)
        return 84;
    array_t *array = malloc(sizeof(array_t));
    parse_map(av[1], array);
    if (array->width > 600 && array->height > 600)
        exit(84);
    start_solver(array);
    return 0;
}
