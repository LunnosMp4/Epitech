/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_str_isupper.c
*/

#include "my.h"

bool my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 'A' || str[i] > 'Z')
            return false;
    return true;
}
