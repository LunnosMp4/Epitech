/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_putchar.c
*/

#include "my.h"

void my_putchar(char ch)
{
    write(1, &ch, 1);
}
