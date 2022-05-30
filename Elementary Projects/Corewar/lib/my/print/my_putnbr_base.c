/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_putnbr_base.c
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int reste = 0;
    int quotient = 0;
    int len_base = my_strlen(base);

    if (nbr < 0)
        nbr += 256;
    quotient = nbr / len_base;
    reste = nbr % len_base;
    if (quotient > 0)
        my_putnbr_base(quotient, base);
    my_putchar(base[reste]);
    return 0;
}

int my_putnbr_longbase(unsigned long int nbr, char const *base)
{
    unsigned long int reste = 0;
    unsigned long int quotient = 0;
    int len_base = my_strlen(base);

    quotient = nbr / len_base;
    reste = nbr % len_base;
    if (quotient > 0)
        my_putnbr_longbase(quotient, base);
    my_putchar(base[reste]);
    return 0;
}
