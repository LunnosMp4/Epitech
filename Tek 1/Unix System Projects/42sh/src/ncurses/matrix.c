/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** matrix.c
*/

#include "my_sh.h"

curse_t *init_param(void)
{
    curse_t *curse = malloc(sizeof(curse_t));

    curse->vertical_length = rand() % 80 + 20;
    curse->basex = rand() % COLS + 1;
    curse->base2x = rand() % COLS + 1;
    curse->base3x = rand() % COLS + 1;
    curse->base4x = rand() % COLS + 1;
    curse->base5x = rand() % COLS + 1;
    curse->basey = 0;
    curse->max_y = LINES;
    curse->ascii_char = 0;
    return curse;
}

void write_line(curse_t *curse, int ascii_range)
{
    attron(COLOR_PAIR(1));
    curse->ascii_char = rand() % ascii_range;
    mvaddch(curse->basey, curse->basex, curse->ascii_char);
    curse->ascii_char = rand() % ascii_range;
    mvaddch(curse->basey, curse->base2x, curse->ascii_char);
    curse->ascii_char = rand() % ascii_range;
    mvaddch(curse->basey, curse->base3x, curse->ascii_char);
    curse->ascii_char = rand() % ascii_range;
    mvaddch(curse->basey, curse->base4x, curse->ascii_char);
    curse->ascii_char = rand() % ascii_range;
    mvaddch(curse->basey, curse->base5x, curse->ascii_char);
    curse->ascii_char = rand() % ascii_range;
    attroff(COLOR_PAIR(1));
}

void writecolumn(int ascii_range)
{
    struct timespec start;
    struct timespec end;
    curse_t *curse = init_param();

    ncurses_input();
    start.tv_sec = 0;
    for (int counter = 0; counter < curse->vertical_length ;counter++) {
        start.tv_nsec = 30000000;
        curse->ascii_char = rand() % ascii_range;
        write_line(curse, ascii_range);
        refresh();
        if (nanosleep(&start, &end) < 0)
            exit_ncurses();
        curse->basey++;
        if (curse->basey > LINES)
            break;
    }
}

void anime_matrix(void)
{
    mvprintw(LINES / 2 + 0 - 5, COLS / 2 - 15,
    "  j88D  .d888b.   .d8888. db   db");
    mvprintw(LINES / 2 + 1 - 5, COLS / 2 - 15,
    " j8~88  VP  `8D   88'  YP 88   88");
    mvprintw(LINES / 2 + 2 - 5, COLS / 2 - 15,
    "j8' 88     odD'   `8bo.   88ooo88");
    mvprintw(LINES / 2 + 3 - 5, COLS / 2 - 15,
    "V88888D  .88'       `Y8b. 88   88");
    mvprintw(LINES / 2 + 4 - 5, COLS / 2 - 15,
    "    88  j88.      db   8D 88   88");
    mvprintw(LINES / 2 + 5 - 5, COLS / 2 - 15,
    "    VP  888888D   `8888Y' YP   YP");
    for (int i = 0; i != 5; i++)
        writecolumn(127);
    exit_ncurses();
}
