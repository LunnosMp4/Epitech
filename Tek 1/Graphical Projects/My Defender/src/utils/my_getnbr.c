/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** My_getnbr
*/

static int pair_impair(char const *str)
{
    int pair = 0;

    for (int i = 0; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            pair++;
    pair = pair % 2;
    if (pair != 0)
        pair = -1;
    else
        pair = 1;
    return pair;
}

int my_getnbr(char const *str)
{
    long int nbr = 0;
    int pair = 0;

    pair = pair_impair(str);
    for (int i = 0; (str[i] >= '0' && str[i] <= '9')
    || str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            nbr = nbr * 10 + str[i] - 48;
    }
    nbr = nbr * pair;
    if (nbr > 2147483647 || nbr < (-2147483648))
        return 0;
    return nbr;
}
