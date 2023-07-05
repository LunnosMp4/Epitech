/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-loic.tisseyre
** File description:
** convert_int_to_string.c
*/

#include "my_defender.h"

static char *convert_int(int str, char *digit, char *arg)
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

char *convert_int_to_string(int lvl, int biome)
{
    char digit[] = "0123456789";
    char *str_biome = malloc(sizeof(char) * 100);
    char *str_map = malloc(sizeof(char) * 100);
    char *arg1 = str_map;
    char *arg2 = str_biome;

    str_map = convert_int(lvl, digit, arg1);
    str_map = my_strcat(str_map, " - Level\n");
    str_biome = convert_int(biome, digit, arg2);
    str_biome = my_strcat(str_biome, " - Biome\n");
    str_map = my_strcat(str_map, str_biome);
    return str_map;
}
