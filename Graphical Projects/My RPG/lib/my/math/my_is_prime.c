/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_is_prime.c
*/

int my_is_prime(int nb)
{
    if (nb % 2 != 0)
        return 1;
    if (nb == 2)
        return 1;
    if ((nb % 2 == 0 && nb != 2) || nb % 3 == 0 || nb <= 1)
        return 0;
    return 0;
}
