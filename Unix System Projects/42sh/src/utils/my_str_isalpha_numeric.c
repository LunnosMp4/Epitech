/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** my_str_isalpha_numeric.c
*/

#include "my_sh.h"

int my_str_isalpha_numeric(const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > 'z')
            return 0;
        if (str[i] > '9' && str[i] < 'A')
            return 0;
        if (str[i] > 'Z' && str[i] < 'a')
            return 0;
    }
    return 1;
}
