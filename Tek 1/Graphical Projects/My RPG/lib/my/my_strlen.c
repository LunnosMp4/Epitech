/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** My_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}
