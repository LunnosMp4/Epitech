/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-loic.tisseyre
** File description:
** my_putstr_S.c
*/

#include "my_lib.h"

int my_putstrs(char const *str)
{
    int i = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar(92);
            my_put_nbr_unsigned(my_get_octal(str[i]));
        } else
            write(1, &str[i++], my_strlen(str));
        return 0;
    }
}
