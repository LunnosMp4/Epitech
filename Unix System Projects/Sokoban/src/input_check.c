/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** input_check.c
*/

#include "my.h"

void exit_sokoban(int return_value)
{
    endwin();
    curs_set(1);
    exit(return_value);
}

void print_game(array_t *array, write_game_t *write_game)
{
    for (int i = 0; i < array->lines + 1; i++) {
        write_game->count = my_strlen(array->newarr[i]);
        write_game->count2 = my_strlen(array->newarr[i]);
        if (LINES < array->lines || COLS < write_game->count2) {
            clear();
            attron(COLOR_PAIR(1));
            mvprintw((LINES / 2), (COLS / 3), "Terminal too small.");
            attroff(COLOR_PAIR(1));
        }
        write_map(array, i, write_game);
    }
}

void exit_print_sokoban(array_t *array,
write_game_t *write_game, int return_value)
{
    clear();
    print_game(array, write_game);
    refresh();
    usleep(100000);
    endwin();
    curs_set(1);
    exit(return_value);
}

void check_keybinds(array_t *array)
{
    int ch = mvgetch(0, 0);
    mvaddch(0, 0, ' ');
    switch (ch) {
        case 27:
            exit_sokoban(0);
            break;
        case KEY_UP:
            movement_up(array);
            break;
        case KEY_DOWN:
            movement_down(array);
            break;
        case KEY_RIGHT:
            movement_right(array);
            break;
        case KEY_LEFT:
            movement_left(array);
            break;
    }
}
