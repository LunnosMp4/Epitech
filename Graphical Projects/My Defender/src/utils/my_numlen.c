/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** my_numlen.c
*/

int my_numlen(int nb)
{
    int len = 1;

    if (nb < 0) {
        len += 1;
        nb = -nb;
    }
    while (nb > 9) {
        len += 1;
        nb /= 10;
    }
    len += 1;
    return len;
}
