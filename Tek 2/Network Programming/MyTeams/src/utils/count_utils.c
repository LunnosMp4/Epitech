/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** count_utils.c
*/

#include "myteams.h"

int count_until(char *str, char *until)
{
    int i = 0;

    for (; strncmp(str, until, strlen(until)) != 0; i++, str++)
        if (*str == '\0')
            return -1;
    return i;
}
