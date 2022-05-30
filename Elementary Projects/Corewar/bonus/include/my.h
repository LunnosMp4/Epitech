/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** my.h
*/

#ifndef __MY_H__
    #define __MY_H__
    #define UNUSED __attribute__((unused))

    #include <stdarg.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <assert.h>
    #include <string.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <pwd.h>
    #include <time.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <stdint.h>
    #include "op.h"

// Number
void my_swap(int *a, int *b);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);

// String
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *str);
char *range_strdup(char const *str, char const *start, char const *stop,
bool count_start);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *strcat_alloc(char const *first, char const *second);
char *strreplace(char *str, char *replace, char *newstr); // A TEST
char *strsorted(char *str, char *cut);
// char *strcatf(...); // A TEST

// Array
void *my_memset(void *ptr, int c, size_t n);
char **strsplit(char *str, char *cut);
int count(char const *str, char ch);
char **split_string(char const *str, char sep);

int count_lines(char *str, char sep);
char **malloc_array(char **arr, int lines, int size);

// Condition
bool ch_isequal(char ch, char const *container);
bool str_isequal(char const *from, char const *to, bool strict);
bool str_contains(char const *content, char const *container);
bool nbr_unsigned(int nb);
bool my_str_isalpha(char const *str);
bool my_str_isnum(char const *str);
bool my_str_islower(char const *str);
bool my_str_isupper(char const *str);
bool my_str_isprintable(char const *str);

// Utils
int nb_cols_2d_array(char **arr);
int find_word(char const *str, char const *word);
int my_strlen(char const *str);
int my_numlen(int nb);
int my_getnbr(char const *str);
int range_strlen(char const *str, char const *start, char const *stop,
bool count_start);

// Print
int my_printf(char *formats, ...);
void my_putchar(char c);
void my_putstr(char const *str);
void my_put_nbr(int nb);
int my_put_nbr_unsigned(int nb);
int my_put_longnbr(long int nb);
int my_putnbr_base(int nbr, char const *base);
int my_putnbr_longbase(unsigned long int nbr, char const *base);
int my_putstr_printable(char const *str);
void my_put_address(char *pointer);

//Only for ptf
void detect_flags_chars(char *flags, va_list ap, int i);
int detect_flags_int(char *flags, va_list ap, int i, int arg);
int detect_flags_op(char *flags, va_list ap, int i, int arg);
void detect_hashflags(char *flags, int i);
int detect_flags_sub_add(char *flags, va_list ap, int i, int arg);
int detect_flags_zero(char *flags, va_list ap, int i, int arg);
void write_space_or_zero(int count, int boel);

#endif /* __MY_H__ */
