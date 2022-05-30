/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main.c
*/

#include "generator.h"

static void fill_arr_x(maze_t *maze, char **av)
{
    maze->width = atoi(av[1]);
    maze->height = atoi(av[2]);
    maze->map = malloc(sizeof(char *) * (maze->height + 1));
    for (int i = 0; i < maze->height; i++)
        maze->map[i] = malloc(sizeof(char) * (maze->width + 1));
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j != maze->width; j++)
            maze->map[i][j] = 'X';
        maze->map[i][maze->width] = '\0';
    }
    maze->map[maze->height] = NULL;
}

int main(int ac, char **av)
{
    maze_t *maze = malloc(sizeof(maze_t));

    srand((unsigned int)time(NULL));
    error_handling(ac, av);
    fill_arr_x(maze, av);
    generate_maze(av, ac, maze);
    return 0;
}
