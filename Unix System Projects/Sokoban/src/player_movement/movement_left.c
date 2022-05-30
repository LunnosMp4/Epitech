/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** movement_left.c
*/

#include "my.h"

void check_movement_left(array_t *array, int i, int j)
{
    if ((array->newarr[i][j] == 'P' && array->newarr[i][j - 1] == ' ') ||
    (array->newarr[i][j] == 'P' && array->newarr[i][j - 1] == 'O')) {
        array->newarr[i][j - 1] = 'P';
        catch_map(array, i, j);
    } else if (array->newarr[i][j] == 'P' && array->newarr[i][j - 1] == 'X'
    && array->newarr[i][j - 2] != '#' && array->newarr[i][j - 2] != 'X') {
        array->newarr[i][j - 1] = 'P';
        array->newarr[i][j - 2] = 'X';
        array->newarr[i][j] = ' ';
        catch_map(array, i, j);
    }
}

int movement_left(array_t *array)
{
    int count = 0;
    for (int i = 0; i < array->lines; i++) {
        count = my_strlen(array->newarr[i]);
        for (int j = 0; j < count; j++) {
            check_movement_left(array, i, j);
        }
    }
    return 0;
}
