/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-loic.tisseyre
** File description:
** my_flags_cases.c
*/

#include "my_lib.h"

void part1(char *s, va_list ap, int i)
{
    switch (s[i]) {
        case 'o':
            my_put_nbr_unsigned(my_get_octal(va_arg(ap, unsigned int)));
            break;
        case 'b':
        case 'B':
            my_put_nbr_base(va_arg(ap, unsigned int), "01");    
            break;
        case 'x':
            my_put_nbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
            break;
        case 'X':   
            my_put_nbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
            break;
    }
}

void part2(char *s, va_list ap, int i)
{
    switch (s[i]) {
        case 'C':
            my_putcharc(va_arg(ap, int));
            break;
        case 'l':
            my_put_nbr_long(va_arg(ap, long));
            break;
        case 'u':
            my_put_nbr_unsigned(va_arg(ap, unsigned int));
            break;
        case '%':
            my_putchar('%');
            break;
    }
}

void flag_case(char *s, va_list ap, int i)
{
    switch (s[i]) {
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case 'S':
            my_putstrs(va_arg(ap, char *));
            break;
        case 'd':
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
    }
    part1(s, ap, i);
    part2(s, ap, i);
}
