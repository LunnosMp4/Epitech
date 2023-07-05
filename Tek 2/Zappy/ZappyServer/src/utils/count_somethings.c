/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** count_somethings
*/

#include "server.h"

int how_many_lines(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);

    return i;
}

int count_until(char *str, char *until)
{
    int i = 0;

    for (; strncmp(str, until, strlen(until)) != 0; i++, str++)
        if (*str == '\0')
            return -1;
    return i;
}

int space_counter(char *str)
{
    int space = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            space++;
    }
    return space;
}
