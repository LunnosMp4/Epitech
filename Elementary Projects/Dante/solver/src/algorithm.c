/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-enzo.daumalle
** File description:
** algorithm.c
*/

#include "solver.h"

void flood_fill(array_t *array, int row, int col, int **maze)
{
    if (row < 0 || row > array->height || col < 0 || col > array->width)
        return;
    if (maze[row][col] != 1)
        return;
    array->count++;
    maze[row][col] = array->count;
    flood_fill(array, row, col - 1, maze);
    flood_fill(array, row + 1, col, maze);
    flood_fill(array, row, col + 1, maze);
    flood_fill(array, row - 1, col, maze);
    return;
}

void find_path(array_t *array, int row, int col, int **maze)
{
    if (maze[row][col + 1] < maze[row][col] && maze[row][col + 1] != 0) {
        array->arr[row][col + 1] = 'o';
        return find_path(array, row, col + 1, maze);
    }
    if (maze[row + 1][col] < maze[row][col] && maze[row + 1][col] != 0) {
        array->arr[row + 1][col] = 'o';
        return find_path(array, row + 1, col, maze);
    }
    if (maze[row][col - 1] < maze[row][col] && maze[row][col - 1] != 0) {
        array->arr[row][col - 1] = 'o';
        return find_path(array, row, col - 1, maze);
    }
    if (maze[row - 1][col] < maze[row][col] && maze[row - 1][col] != 0) {
        array->arr[row - 1][col] = 'o';
        return find_path(array, row - 1, col, maze);
    }
}