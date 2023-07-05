/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** My_put_nbr
*/

#include "my.h"

int my_put_longnbr(long int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }

    if (nb > 9) {
        int c = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(c + 48);
    } else {
        my_putchar(nb + 48);
    }
    return (0);
}
