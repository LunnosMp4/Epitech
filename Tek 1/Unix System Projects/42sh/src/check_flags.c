/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-enzo.daumalle
** File description:
** check_flags.c
*/

#include "my_sh.h"

static void lauch_ncurses(void)
{
    if (isatty(STDIN_FILENO))
        create_ncurses();
}

static void help_display(void)
{
    printf("USAGE : ./42sh\n");
    printf("\t-h : show this help.\n");
    printf("\t-g : displays an animation on launch.\n");
    exit(0);
}

void check_flags(int ac, char **av)
{
    for (int i = 0; i < ac; i++) {
        if (str_isequal(av[i], "-h", true))
            help_display();
        if (str_isequal(av[i], "-g", true))
            lauch_ncurses();
    }
}
