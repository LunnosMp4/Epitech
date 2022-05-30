/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** my_putchar
*/

#include "my_lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
