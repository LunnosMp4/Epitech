/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** my putstr
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    int arg = 0;

    while (str[arg]) {
        my_putchar(str[arg]);
        arg++;
    }
}
