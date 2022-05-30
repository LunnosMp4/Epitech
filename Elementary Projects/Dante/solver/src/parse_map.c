/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-enzo.daumalle
** File description:
** read_file.c
*/

#include "solver.h"

static char *read_file(char *filepath, char *buffer, int fd)
{
    struct stat st;
    size_t size = 0;

    stat(filepath, &st);
    buffer = malloc(st.st_size + 1);
    size = read(fd, buffer, st.st_size);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}

void parse_map(char *filepath, array_t *array)
{
    int fd = 0;
    char *buffer = NULL;

    array->arr = NULL;
    array->height = 0;
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        exit(84);
    buffer = read_file(filepath, buffer, fd);
    save_map(buffer, array);
    free(buffer);
}
