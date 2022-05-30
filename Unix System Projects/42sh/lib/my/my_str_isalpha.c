/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_str_isalpha.c
*/

#include "my.h"

bool my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 'A' || str[i] > 'z')
            return false;
        else if (str[i] > 'Z' && str[i] < 'a')
            return false;
    }
    return true;
}
