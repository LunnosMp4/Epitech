/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** display_map.c
*/

#include "my.h"

void write_map3(array_t *array, int i, int j, write_game_t *write_game)
{
    if (array->newarr[i][j] == 'X') {
        attron(COLOR_PAIR(4));
        mvaddch(write_game->basey, write_game->basex, array->newarr[i][j]);
        attroff(COLOR_PAIR(4));
    }
}

void write_map2(array_t *array, int i, int j, write_game_t *write_game)
{
    if (array->newarr[i][j] == 'P') {
        attron(COLOR_PAIR(1));
        mvaddch(write_game->basey, write_game->basex, array->newarr[i][j]);
        attroff(COLOR_PAIR(1));
    } else if (array->newarr[i][j] == 'O') {
        attron(COLOR_PAIR(3));
        mvaddch(write_game->basey, write_game->basex, array->newarr[i][j]);
        attroff(COLOR_PAIR(3));
    }
    write_map3(array, i, j, write_game);
}

void write_map(array_t *array, int i, write_game_t *write_game)
{
    for (int j = 0; j < write_game->count; j++) {
        write_game->basey = (LINES / 1.5) - array->lines + i + 1;
        write_game->basex = (COLS / 2) - write_game->count2 + j;
        write_map2(array, i, j, write_game);
        if (array->newarr[i][j] == '#'){
            attron(COLOR_PAIR(5));
            mvaddch(write_game->basey, write_game->basex, array->newarr[i][j]);
            attroff(COLOR_PAIR(5));
        } else if (array->newarr[i][j] == ' ') {
            mvaddch(write_game->basey, write_game->basex, array->newarr[i][j]);
        }
    }
}
