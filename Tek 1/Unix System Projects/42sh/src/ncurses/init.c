/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** init.c
*/

#include "my_sh.h"

void init_ncurses(void)
{
    initscr();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
}

void exit_ncurses(void)
{
    endwin();
    exit(0);
}

void create_ncurses(void)
{
    pid_t pid;
    srand(time(NULL));

    pid = fork();
    if (pid == 0) {
        init_ncurses();
        anime_matrix();
    } else
        wait(NULL);
    printf("\e[1;1H\e[2J");
}
