/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** movement_down.c
*/

#include "my.h"

int check_movement_down(array_t *array, int i, int j, int c)
{
    if ((array->newarr[i][j] == 'P' && array->newarr[i + 1][j] == ' ') ||
    (array->newarr[i][j] == 'P' && array->newarr[i + 1][j] == 'O')) {
        array->newarr[i + 1][j] = 'P';
        catch_map(array, i, j);
        c++;
    } if ((array->newarr[i][j] == 'P' && array->newarr[i + 1][j] == 'X'
    && array->newarr[i + 2][j] != '#' && array->newarr[i + 2][j] != 'X')) {
        array->newarr[i + 1][j] = 'P';
        array->newarr[i + 2][j] = 'X';
        array->newarr[i][j] = ' ';
        catch_map(array, i, j);
        c++;
    }
    return c;
}

int movement_down(array_t *array)
{
    int count = 0;
    for (int i = 0, c = 0; i < array->lines; i++) {
        count = my_strlen(array->newarr[i]);
        for (int j = 0; j < count; j++) {
            c = check_movement_down(array, i, j, c);
            if (c == 1)
                break;
        }
    }
    return 0;
}
