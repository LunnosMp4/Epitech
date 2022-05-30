/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** read_file.c
*/

#include "my_sh.h"

char *read_file(char *path, int *fd)
{
    int nread = 0;
    char *buffer = NULL;
    struct stat st;

    *fd = open(path, O_RDONLY);
    if (*fd == -1)
        return NULL;
    stat(path, &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    nread = read(*fd, buffer, st.st_size);
    buffer[nread] = '\0';
    close(*fd);
    return buffer;
}
