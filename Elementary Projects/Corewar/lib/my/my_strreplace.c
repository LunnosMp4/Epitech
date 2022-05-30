/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** my_strreplace.c
*/

#include "my.h"

char *strreplace(char *str, char *replace, char *newstr)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i]) {
        if (str_isequal(str + i, replace, false))
            while (newstr[j])
                result[k++] = newstr[j++];
        else
            result[k++] = str[i];
        i++;
    }
    if (!str[i])
        return str;
    result[k] = '\0';
    return result;
}
