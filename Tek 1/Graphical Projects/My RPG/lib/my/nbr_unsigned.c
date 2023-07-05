/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** nbr_unsigned_int.c
*/

#include "my.h"

bool nbr_unsigned(int nb)
{
    if (nb < 0)
        return false;
    return true;
}
