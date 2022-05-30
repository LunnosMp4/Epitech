/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-enzo.daumalle
** File description:
** solver.c
*/

#include "solver.h"

static void print_maze(array_t *array)
{
    int i = 0;

    for (; i != array->height - 2; i++)
        printf("%s\n", array->arr[i]);
    printf("%s\n", array->arr[i]);
    printf("%s", array->arr[i + 1]);
}

static void free_maze(array_t *array, int **maze)
{
    free(array->arr);
    for (int i = 0; i < array->height; i++)
        free(maze[i]);
}

static void replace_binary(char *arr, int *maze)
{
    if (*arr == '*')
        *maze = 1;
    if (*arr == 'X')
        *maze = 0;
}

void start_solver(array_t *array)
{
    int *maze[array->height];

    array->count = 1;
    for (int i = 0; i <= array->height; i++)
        maze[i] = (int *) malloc(array->width * sizeof(int));
    for (int i = 0; i != array->height; i++)
        for (int j = 0; j != array->width; j++)
            replace_binary(&array->arr[i][j], &maze[i][j]);
    if (array->arr[array->height - 1][array->width - 1] != '*')
        exit(84);
    flood_fill(array, array->height - 1, array->width - 1, maze);
    array->arr[0][0] = 'o';
    find_path(array, 0, 0, maze);
    print_maze(array);
    free_maze(array, maze);
}
