/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** my put str
*/

#include <unistd.h>

void my_putchar(char c);
int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int i = 0;

    write(1, &str[i++], my_strlen(str));
    return 0;
}
