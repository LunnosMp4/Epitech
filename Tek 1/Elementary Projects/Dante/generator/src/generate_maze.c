/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-dante-enzo.daumalle
** File description:
** generate_maze.c
*/

#include "generator.h"

static void fill_arr_star(maze_t *maze, int i)
{
    for (int j = 0; j < maze->width; j++)
        if (i % 2)
            maze->map[i][j] = '*';
}

static void imperfect_maze(maze_t *maze)
{
    for (int i = 0; i < maze->height; i++)
        for (int j = 0; rand() % maze->width / 4; j++)
            maze->map[i][rand() % maze->width] = '*';
}

void generate_maze(char **av, int ac, maze_t *maze)
{
    maze->map[0][0] = '*';
    if (maze->width != 1)
        maze->map[maze->height - 1][maze->width - 2] = '*';
    maze->map[maze->height - 1][maze->width - 1] = '*';
    for (int i = 0; i < maze->height; i++)
        fill_arr_star(maze, i);
    for (int i = 1; i < maze->height; i++)
        maze->map[i][rand() % maze->width] = '*';
    if (ac < 4)
        imperfect_maze(maze);
    else if (ac == 5 && strcmp(av[3], "perfect"))
        exit(84);
    for (int i = 0; maze->map[i]; i++)
        if (i == maze->height - 1)
            printf("%s", maze->map[i]);
        else
            printf("%s\n", maze->map[i]);
}