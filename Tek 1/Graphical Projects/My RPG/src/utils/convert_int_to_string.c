/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** convert_int_to_string.c
*/

#include "my_rpg.h"

char *convert_int(int str, char *digit, char *arg)
{
    int string = str;

    if (str < 0) {
        *arg++ = '-';
        str = str * -1;
    }
    while (string) {
        arg++;
        string = string / 10;
    }
    *arg = '\0';
    while (str) {
        *--arg = digit[str % 10];
        str = str / 10;
    }
    return arg;
}

char *convert_int_to_text(int value, char *str)
{
    char digit[] = "0123456789";
    char *value_text = malloc(sizeof(char) * 100);
    char *arg1 = value_text;

    value_text = convert_int(value, digit, arg1);
    value_text = my_strcat(value_text, str);
    return value_text;
}
