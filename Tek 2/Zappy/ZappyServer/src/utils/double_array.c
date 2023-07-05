/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** double_array
*/

#include "server.h"

void add_space(char *str)
{
    int len = strlen(str);

    if (len >= 2 && str[0] == '[' && str[1] == ',') {
        memmove(str + 2, str + 1, len - 1);
        str[1] = ' ';
        len++;

        if (str[len - 2] == ',') {
            str[len - 2] = '\0';
        }
    }
}

char **copy_double_array(char **src, int index)
{
    int i = index;
    int j = 0;
    int size = 0;

    if (src == NULL || src[0] == NULL)
        return NULL;

    for (; src[i] != NULL; i++, size++);

    char **dest = malloc(sizeof(char*) * (size + 1));

    for (i = index; src[i] != NULL; i++, j++) {
        dest[j] = strdup(src[i]);
    }
    dest[j] = NULL;
    return dest;
}
