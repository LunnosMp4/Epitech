/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** str cat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int arg;
    arg = 0;

    int dest_len = my_strlen(dest);

    while (arg < nb && src[arg] != '\0') {
        dest[dest_len + arg] = src[arg];
        arg++;
    }

    dest[dest_len + arg] = '\0';

    return dest;
}
