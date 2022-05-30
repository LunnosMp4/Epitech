/*
** EPITECH PROJECT, 2021
** MY PUTSTR
** File description:
** ...
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != 0 ) {
        my_putchar(str[i]);
        i += 1;
    }
    return 0;
}

int my_strlen(char const *str)
{
    int arg;
    arg = 0;

    while (str[arg] != '\0') {
        arg++;
    }
    return arg;
}

char **str_to_wordarray(char *buffer, char **arr, array_t *array)
{
    int i = 0;
    int c = 0;
    int j = 0;
    arr = malloc(sizeof(char *) * array->lines);

    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            c++;
        arr[c] = malloc(sizeof(char) * (i + 1));
    }
    for (i = 0, c = 0; buffer[i] != '\0'; i++, j++) {
        if (buffer[i] == '\n') {
            arr[c][i] = '\0';
            c++;
            i++;
            j = 0;
        }
        arr[c][j] = buffer[i];
    }
    return arr;
}
