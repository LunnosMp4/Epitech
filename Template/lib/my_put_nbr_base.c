/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-loic.tisseyre
** File description:
** my_putnbr_base.c
*/

#include "my_lib.h"

int my_put_nbr_base(unsigned int nb, char *base)
{
    int i;
    int arg;
    if (nb == -2147483648)
        return nb;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    arg = my_strlen(base);
    i = nb % arg;
    nb = nb / arg;
    if (nb > 0) {
        my_put_nbr_base(nb, base);
    }
    my_putchar(base[i]);
    return nb;
}
