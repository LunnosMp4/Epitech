/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-edgar.falcou
** File description:
** my_getnbr.c
*/

int check_minus(char const *str)
{
    int arg = 0;
    int i = 0;

    while (str[i] == 43 || str[i] == 45) {
        if (str[i] == 45) {
            arg++;
        }
        i++;
    }
    arg %= 2;
    if (arg != 0) {
        arg = -1;
    } else if (arg == 0) {
        arg = 1;
    }
    return arg;
}

int my_getnbr(char const *str)
{
    long nbr = 0;
    int arg = 0;
    int i = 0;
    arg = check_minus(str);

    while (str[i] >= 48 && str[i] <= 57) {
        if (str[i] >= 48 && str[i] <= 57) {
            nbr *= 10;
            nbr = nbr + str[i] - 48;
        }
        i++;
    }
    if (nbr > 2147483647 || nbr < (-2147483648)) {
        return 0;
    }
    return nbr * arg;
}
