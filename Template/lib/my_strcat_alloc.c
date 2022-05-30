/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_strcat.c
*/

#include "my_lib.h"

char *strcat_alloc(char const *dest, char const *str)
{
    char *new_str = NULL;
    int i = 0;
    int j = 0;

    if (dest == NULL || str == NULL)
        return (NULL);
    new_str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(str) + 1));
    if (new_str == NULL)
        return (NULL);
    while (dest[i] != '\0') {
        new_str[i] = dest[i];
        i++;
    }
    while (str[j] != '\0') {
        new_str[i] = str[j];
        i++;
        j++;
    }
    new_str[i] = '\0';
    return (new_str);
}

