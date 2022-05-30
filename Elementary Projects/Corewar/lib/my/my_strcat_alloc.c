/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_strcat.c
*/

#include "my.h"

char *strcat_alloc(char const *first, char const *second)
{
    int i = 0;
    int j = 0;
    char *str =
    malloc(sizeof(char) * (my_strlen(first) + my_strlen(second) + 1));

    if (!str)
        return NULL;
    while (first[i]) {
        str[i] = first[i];
        i++;
    }
    while (second[j]) {
        str[i] = second[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return str;
}
