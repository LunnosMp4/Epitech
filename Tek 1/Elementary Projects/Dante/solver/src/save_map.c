/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** parse_map.c
*/

#include "solver.h"

static void count_line(char *buffer, array_t *arr)
{
    int i = 0;

    for (; buffer[i]; i++)
        if (buffer[i] == '\n')
            arr->height++;
    if (buffer[i - 1] != '\n') {
        arr->height++;
        i += 1;
    }
    arr->width = (i - arr->height) / arr->height;
}

void save_map(char *buffer, array_t *arr)
{
    count_line(buffer, arr);
    arr->arr = malloc(sizeof(char *) * (arr->height + 1));
    for (int y = 0, i = 0; y <= arr->height - 1; y++) {
        arr->arr[y] = malloc(sizeof(char) * (arr->width + 1));
        for (int x = 0; x <= arr->width; x++)
            arr->arr[y][x] = buffer[i++];
        arr->arr[y][arr->width] = '\0';
    }
    arr->arr[arr->height] = NULL;
}
