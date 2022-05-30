/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-bsmyls-loic.tisseyre
** File description:
** my_printf.c
*/

#include "my_lib.h"

int my_printf(char *s, ...)
{
    int i = 0;
    va_list(ap);
    va_start(ap, s);

    for (i; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            i++;
            flag_case(s, ap, i);
        } else {
            my_putchar(s[i]);
        }
    }
    va_end(ap);
    return 0;
}
