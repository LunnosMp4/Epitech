/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_strcapitalize.c
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (int i = 0; str[i]; i++) {
        if (str[i] < 'A' || str[i] > 'z' || ((str[i] > 'Z' && str[i] < 'a')
        && (str[i + 1] >= 'a' && str[i + 1] <= 'z')))
            str[i + 1] -= 32;
    }
    return str;
}
