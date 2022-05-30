/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** My_strcmp
*/

#include "my_lib.h"

int my_strcmp(char *s1, char *s2)
{
    int result = 0;
    char *a = s1;
    char *b = s2;
    for (result = 0; s1[result] != '\0'; result++) {
        if (s1[result] != s2[result]) {
            return s2[result] - s1[result];
        }
    }
    return 0;
}
