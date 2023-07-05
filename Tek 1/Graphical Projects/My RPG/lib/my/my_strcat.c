/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int len = my_strlen(dest);

    for (i = 0; src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
