/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** My_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int n = 1;

    if (p == 0)
        return 1;
    if (p <= -1)
        return 0;
    n = nb * my_compute_power_rec(nb, p - 1);
    return n;
}
