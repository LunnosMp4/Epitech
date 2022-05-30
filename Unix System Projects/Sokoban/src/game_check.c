/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** game_check.c
*/

#include "my.h"

static int check_pos(array_t *array, int i, int j, int o_number)
{
    if (array->oldarr[i][j] == 'O') {
        o_number++;
    }
    if (array->oldarr[i][j] == 'O' && array->newarr[i][j] == 'X') {
        o_number--;
    }
    return o_number;
}

bool win_loop(array_t *array, int count)
{
    int o_number = 0;

    for (int i = 0; i < array->lines; i++) {
        count = my_strlen(array->newarr[i]);
        for (int j = 0; j < count; j++) {
            o_number = check_pos(array, i, j, o_number);
        }
    }
    if (o_number == 0)
        return true;
    return false;
}

int win_check(array_t *array)
{
    int count = 0;

    if (win_loop(array, count) == true)
        return 1;
    return 0;
}
