/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-enzo.daumalle
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include "my.h"
#include <stdio.h>

void detect_flags_chars(char *flags, va_list ap, int i)
{
    switch (flags[i]) {
        case 's': my_putstr(va_arg(ap, char *));
            break;
        case 'p': my_put_address(va_arg(ap, char *));
            break;
        case 'S': my_putstr_printable(va_arg(ap, char *));
            break;
        case 'c': my_putchar((int) va_arg(ap, int));
            break;
        case '%': my_putchar('%');
            break;
        default:
            break;
    }
}

int detect_flags_int(char *flags, va_list ap, int i, int arg)
{
    switch (flags[i]) {
        case 'd':
        case 'i': my_put_nbr(arg);
            break;
        case 'u': my_put_nbr_unsigned(arg);
            break;
        case 'o': my_putnbr_base(arg, "01234567");
            break;
        case 'X': my_putnbr_base(arg, "0123456789ABCDEF");
            break;
        case 'x': my_putnbr_base(arg, "0123456789abcdef");
            break;
        case 'b': my_putnbr_base(arg, "01");
            break;
        default: detect_flags_chars(flags, ap, i);
            break;
    }
    return i;
}
