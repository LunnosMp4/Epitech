/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** print_something.c
*/

#include "asm.h"

void asm_usage(void)
{
    my_printf("USAGE\n./asm file_name[.s]\n");
    my_printf("DESCRIPTION\nfile_name file in assembly language ");
    my_printf("to be converted into file_name.cor, an\n");
    my_printf("executable in the Virtual Machine.\n");
}
