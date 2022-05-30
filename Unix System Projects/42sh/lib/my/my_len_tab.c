/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** my_len_tab.c
*/

#include "my.h"

int my_len_tab(char **tab)
{
    int i = 0;

    if (!tab)
        return -1;
    for (; tab[i]; i++);
    return i;
}
