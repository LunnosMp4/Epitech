/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** movement_right.c
*/

#include "my.h"

int check_movement_right(array_t *array, int i, int j, int c)
{
    if ((array->newarr[i][j] == 'P' && array->newarr[i][j + 1] == ' ') ||
    (array->newarr[i][j] == 'P' && array->newarr[i][j + 1] == 'O')) {
        array->newarr[i][j + 1] = 'P';
        catch_map(array, i, j);
        c++;
    } else if (array->newarr[i][j] == 'P' && array->newarr[i][j + 1] == 'X'
    && array->newarr[i][j + 2] != '#' && array->newarr[i][j + 2] != 'X') {
        array->newarr[i][j + 1] = 'P';
        array->newarr[i][j + 2] = 'X';
        array->newarr[i][j] = ' ';
        catch_map(array, i, j);
        c++;
    }
    return c;
}

void go_right(array_t *array, int i, int count)
{
    count = my_strlen(array->newarr[i]);
    for (int j = 0, c = 0; j < count; j++) {
        c = check_movement_right(array, i, j, c);
        if (c == 1)
            break;
    }
}

int movement_right(array_t *array)
{
    int count = 0;
    for (int i = 0; i < array->lines; i++) {
        go_right(array, i, count);
    }
    return 0;
}
