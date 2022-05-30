/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_swap.c
*/

void my_swap(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
}
