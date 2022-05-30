/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** ncurses.h
*/

#ifndef __NCURSES_H__
    #define __NCURSES_H__
    #include <ncurses.h>
    #include <curses.h>
    #include <time.h>
    #include <sys/time.h>

typedef struct curse {
    int basex;
    int base2x;
    int base3x;
    int base4x;
    int base5x;
    int basey;
    int max_y;
    int vertical_length;
    int ascii_char;
} curse_t;

void create_ncurses(void);
void init_ncurses(void);
void ncurses_input(void);
void exit_matrix(void);
void exit_ncurses(void);
void anime_matrix(void);

#endif
