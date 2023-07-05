/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** space_inhibitors.c
*/

#include "my_sh.h"

void fix_space_inhibitors(inhibitors_t *ibt, int i)
{
    for (ibt->j = i; ibt->j < my_strlen(ibt->new_str); ibt->j++)
        ibt->new_str[ibt->j] = ibt->new_str[ibt->j + 1];
}
