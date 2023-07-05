/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** args_management
*/

#include "server.h"

char *get_command(char **str)
{
    char *command = malloc(sizeof(char) * (strlen(*str) + 1));
    int i = 0;

    for (; **str != ' ' && **str != '\0'; i++, (*str)++) {
        command[i] = **str;
    }
    command[i] = '\0';
    (*str)++;

    return command;
}

char **get_args(char **dest, char *src, int spaces_nb)
{
    size_t k = 0;
    int j = 0;
    for (int i = 1; i - 1 != spaces_nb && k < strlen(src); i++, k++) {
        for (j = 0; src[k] != '\n' && src[k] != '\0'; j++, k++) {
            dest[i][j] = src[k];
        }
        dest[i][j] = '\0';
    }

    return dest;
}

char **split_args(char *str)
{
    int max = space_counter(str);
    char **result = malloc(sizeof(char*) * (max + 2));
    for (int i = 0; i != max + 1; i++) {
        result[i] = malloc(sizeof(char*) * (strlen(str) + 1));
        memset(result[i], '\0', strlen(str) + 1);
    }
    result[max + 1] = NULL;
    result[0] = get_command(&str);
    result = get_args(result, str, max);
    return result;
}
