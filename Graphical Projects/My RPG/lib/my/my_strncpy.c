/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_strncpy.c
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i]) {
        dest[i] = src[i];
        i++;
    }
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}
