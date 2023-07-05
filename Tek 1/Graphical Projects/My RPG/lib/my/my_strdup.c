/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** my_strdup.c
*/

#include "my.h"

char *my_strdup(char const *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    if (!new_str)
        return NULL;
    for (i = 0; str[i]; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return new_str;
}
