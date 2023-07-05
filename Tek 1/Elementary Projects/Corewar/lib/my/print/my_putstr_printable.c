/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_putstr_printable.c
*/

#include "my.h"

int my_putstr_printable(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] <= 32 || str[i] == 127) {
            my_putchar('\\');
            my_putchar('0');
            my_putnbr_base(str[i], "01234567");
        } else
            my_putchar(str[i]);
    }
    return 0;
}
