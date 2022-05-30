/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_str_isnum.c
*/

#include "my.h"

bool my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}
