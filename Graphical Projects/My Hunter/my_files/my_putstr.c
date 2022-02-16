/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** my put str
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int arg = 0;

    while (str[arg] != '\0') {
        my_putchar(str[arg]);
        arg += 1;
    }
    return 0;
}
