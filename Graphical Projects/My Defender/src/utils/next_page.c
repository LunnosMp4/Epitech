/*
** EPITECH PROJECT, 2021
** My Defender
** File description:
** next_page.c
*/

#include "my_defender.h"

void next_page(int *state, int max)
{
    if (*state == max)
        *state = 0;
    *state += 1;
}
