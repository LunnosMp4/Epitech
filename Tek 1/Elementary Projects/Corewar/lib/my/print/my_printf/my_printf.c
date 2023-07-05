/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-enzo.daumalle
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void write_space_or_zero(int count, int boel)
{
    if (boel == 43)
        count--;
    while (count > 0) {
        if (boel == 1)
            my_putchar('0');
        else
            my_putchar(' ');
        count--;
    }
    if (boel == 43)
        my_putchar('+');
}

static int arg_check_int(char *formats, int i, va_list ap)
{
    int arg = 0;

    if (ch_isequal(formats[i], "diouXxb#+-0123456789"))
        arg = (int) va_arg(ap, int);
    return arg;
}

int my_printf(char *formats, ...)
{
    va_list ap;
    int arg;

    va_start (ap, *formats);
    for (int i = 0; formats[i]; i++) {
        if (formats[i] == '%') {
            i++;
            arg = -1;
            arg = arg_check_int(formats, i, ap);
            i = detect_flags_op(formats, ap, i, arg);
        } else {
            my_putchar(formats[i]);
        }
    }
    va_end(ap);
    return EXIT_SUCCESS;
}
