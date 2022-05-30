/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-bsmyls-loic.tisseyre
** File description:
** my_lib.h
*/

#ifndef __MY_LIB__
    #define __MY_LIB__
    #include <stdarg.h>
    #include <stdlib.h>
    #include <unistd.h>

void flag_case(char *s, va_list ap, int i);
void my_putcharc(char c);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putstrs(char const *str);
int my_put_nbr_long(long nb);
int my_put_nbr_base(unsigned int nb, char *base);
int my_put_nbr_unsigned(unsigned int nb);
char *my_strcat(char *dest , char const *str);
char *strcat_alloc(char const *dest, char const *str);
int my_str_isnum(char const *str);
int my_strcmp(char *s1, char *s2);
char *my_strcapitalize (char *str);
char *my_strlowcase(char * str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_get_octal(int arg);
int my_printf(char *s, ...);

#endif
