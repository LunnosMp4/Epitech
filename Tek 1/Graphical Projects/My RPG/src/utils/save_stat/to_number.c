/*
** EPITECH PROJECT, 2021
** lib
** File description:
** to_number.c
*/

#include "my_rpg.h"

int to_number(char const *str)
{
    int sign = 1;
    long long int res = 0;

    while (45 == *str || 43 == *str) {
        if (*str == 45)
            sign *= -1;
        str++;
    }
    while (*str >= 48 && *str <= 57) {
        res = res * 10 + (*str - 48) * sign;
        str++;
        if (res < -2147483648 || res > 2147483647)
            return 0;
    }
    return res;
}
