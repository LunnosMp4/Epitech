/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
** File description:
** movement.c
*/

#include "my.h"

void catch_map(array_t *array, int i, int j)
{
    if (array->oldarr[i][j] == 'O')
        array->newarr[i][j] = 'O';
    else
        array->newarr[i][j] = ' ';
}
