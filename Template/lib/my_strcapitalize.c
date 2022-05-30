/*
** EPITECH PROJECT, 2021
** my_strcapitalize.c
** File description:
** capitalize
*/

#include "my_lib.h"

char *my_strcapitalize (char *str)
{
    int arg = 0;
    my_strlowcase(str);

    for (arg; str[arg] != '\0'; arg++) {
        if (str[arg] >= 48 && str[arg] <= 57)
            arg++;
        if (str[arg - 1] == 0 || str[arg - 1] == 32 ||
            str[arg - 1] == '+' || str[arg - 1] == '-')
            str[arg] = str[arg] - 32;
    }
    return (str);
}
