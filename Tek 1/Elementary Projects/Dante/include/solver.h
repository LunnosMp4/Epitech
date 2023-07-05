/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my.h
*/

#ifndef SOLVER_H
    #define SOLVER_H
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <time.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #define CAN_ACCESS(row, col) (row > 0 || row < array->height\
    || col > 0 || col < array->width)

typedef struct array {
    char **arr;
    int height;
    int width;
    int count;
} array_t;

void save_map(char *buffer, array_t *arr);
void flood_fill(array_t *array, int row, int col, int **maze);
void find_path(array_t *array, int row, int col, int **maze);
void parse_map(char *filepath, array_t *array);
void start_solver(array_t *arr);

#endif
