/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av) == -1)
        return 84;
    if (allocate_map(av[1]) == -1)
        return 84;
    return 0;
}
