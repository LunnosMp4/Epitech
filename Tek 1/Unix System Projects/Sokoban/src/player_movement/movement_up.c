/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** movement_up.c
*/

#include "my.h"

void check_movement_up(array_t *array, int i, int j)
{
    if ((array->newarr[i][j] == 'P' && array->newarr[i - 1][j] == ' ') ||
    (array->newarr[i][j] == 'P' && array->newarr[i - 1][j] == 'O')) {
        array->newarr[i - 1][j] = 'P';
        catch_map(array, i, j);
    } else if (array->newarr[i][j] == 'P' && array->newarr[i - 1][j] == 'X'
    && array->newarr[i - 2][j] != '#' && array->newarr[i - 2][j] != 'X') {
        array->newarr[i - 1][j] = 'P';
        array->newarr[i - 2][j] = 'X';
        array->newarr[i][j] = ' ';
        catch_map(array, i, j);
    }
}

int movement_up(array_t *array)
{
    int count = 0;
    for (int i = 0; i < array->lines; i++) {
        count = my_strlen(array->newarr[i]);
        for (int j = 0; j < count; j++) {
            check_movement_up(array, i, j);
        }
    }
    return 0;
}
