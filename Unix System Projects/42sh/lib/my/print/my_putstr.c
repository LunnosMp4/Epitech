/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_putstr.c
*/

#include "my.h"

void my_putstr(char const *str)
{
    int i = 0;

    write(1, &str[i++], my_strlen(str));
}
