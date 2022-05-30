/*
** EPITECH PROJECT, 2021
** my_str_isnum.c
** File description:
** is num
*/

int my_str_isnum(char const *str)
{
    int arg = 0;

    for (arg; str[arg] != '\0'; arg++) {
        if (str[arg] < 48 || str[arg] > 57) {
            return (0);
        }
    }
    return (1);
}
