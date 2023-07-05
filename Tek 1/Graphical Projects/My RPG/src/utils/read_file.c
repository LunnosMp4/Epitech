/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** read_file.c
*/

#include "my_rpg.h"

char *read_file(char *path)
{
    int fd = open(path, O_RDONLY);
    int nread = 0;
    char *buffer = NULL;
    struct stat st;
    if (fd == -1)
        return NULL;
    stat(path, &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    nread = read(fd, buffer, st.st_size);
    buffer[nread] = '\0';
    close(fd);
    return buffer;
}
