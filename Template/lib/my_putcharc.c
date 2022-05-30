/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** my_putchar
*/

#include "my_lib.h"
#include <unistd.h>

void my_putcharc(char c)
{
    if (c > 64 && c < 91) {
        write(1, &c, 1);
    }
}
