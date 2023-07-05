/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** My_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int n = 0;
    int i = 0;

    if (nb <= 0)
        return 0;
    for (i = 0; i < 46341; i++) {
        n = i * i;
        if (nb == n)
            return i;
        else if (nb < n)
            return 0;
    }
    return 0;
}
