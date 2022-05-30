/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** matrix.c
*/

#include "my_sh.h"

void ncurses_input(void)
{
    int input = getch();

    if (input == 27)
        exit_ncurses();
}
