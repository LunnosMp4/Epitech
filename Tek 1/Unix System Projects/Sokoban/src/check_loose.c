/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** check_loose.c
*/

#include "my.h"

int check_block(array_t *array, int i, int j)
{
    if (array->newarr[i][j] == 'X') {
        if ((array->newarr[i - 1][j] == '#' && (array->newarr[i][j - 1] == '#'
        || array->newarr[i][j + 1] == '#')) ||
        (array->newarr[i + 1][j] == '#' && (array->newarr[i][j - 1] == '#'
        || array->newarr[i][j + 1] == '#'))) {
            return 1;
        }
    }
    return 0;
}

bool loose_loop(array_t *array, int count)
{
    for (int i = 0; i < array->lines; i++) {
        count = my_strlen(array->newarr[i]);
        for (int j = 0; j < count; j++) {
            if (check_block(array, i, j) == 1)
                return true;
        }
    }
    return false;
}

int loose_check(array_t *array)
{
    int count = 0;

    if (loose_loop(array, count) == true)
        return 1;
    return 0;
}
