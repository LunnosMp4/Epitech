/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** my strlen4
*/

int my_strlen(char const *str)
{
    int arg;

    arg = 0;
    while (str[arg])
        arg++;
    return (arg);
}
