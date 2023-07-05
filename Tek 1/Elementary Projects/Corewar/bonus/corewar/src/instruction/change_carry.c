/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** change_carry.c
*/

#include "corewar.h"

void change_carry(process_t *process)
{
    if (process->carry == 0)
        process->carry = 1;
    else
        process->carry = 0;
}
