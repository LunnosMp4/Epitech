/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** my strlen4
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int arg;
    arg = 0;

    while (str[arg] != '\0') {
        arg++;
    }
    return (arg);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    write(1, &str[i++], my_strlen(str));
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_put_nbr(147483648);
        return (0);
    }
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb > 9) {
        int c = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(c + 48);
    } else if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int arg = 0;
    int isneg = 1;
    int i = 0;

    for (i = 0; str[i] == 45; i++) {
        if (str[i] == 45)
            isneg = isneg * -1;
    }
    for (i; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            arg *= 10;
            arg += str[i] - 48;
        } else {
            return arg * isneg;
        }
    }
    return arg * isneg;
}
