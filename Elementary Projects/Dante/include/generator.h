/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my.h
*/

#ifndef GENERATOR_H
    #define GENERATOR_H
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <time.h>
    #include <sys/stat.h>
    #include <fcntl.h>

typedef struct maze {
    char **map;
    int width;
    int height;
    int random;
} maze_t;

void error_handling(int ac, char **av);
void generate_maze(char **av, int ac, maze_t *maze);
void create_way(int ac, maze_t *maze);

#endif
