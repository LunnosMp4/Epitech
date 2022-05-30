/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** calc_math.c
*/

int	modulo_op(int nb, int modulo)
{
    nb = nb % modulo;
    if (nb < 0)
    nb = modulo + nb;
    return nb;
}
