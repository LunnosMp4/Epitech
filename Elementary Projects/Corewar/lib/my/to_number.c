/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** to_number
*/

#include "my.h"

int to_number(char const *str)
{
    int i = 0;
    int res = 0;
    int j = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            j++;
            i++;
        } else
            i++;
    }
    while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0') {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if (j % 2 == 1)
        res = res * -1;
    return res;
}
