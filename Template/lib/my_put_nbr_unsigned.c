/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** put nbr
*/

#include "my_lib.h"

int my_put_nbr_unsigned(unsigned int nb)
{
    if (nb < 0) {
        nb = 4294967295;
        my_put_nbr(nb);
    }
    if (nb > 9) {
        int c = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(c + 48);
    } else if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    return (0);
}
