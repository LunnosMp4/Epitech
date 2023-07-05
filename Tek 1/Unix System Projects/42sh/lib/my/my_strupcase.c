/*
** EPITECH PROJECT, 2021
** my_strupcase.c
** File description:
** My_strupcase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return str;
}
