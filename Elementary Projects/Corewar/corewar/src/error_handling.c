/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** error_handling.c
*/

#include "corewar.h"

void help_display(int ac, char **av)
{
    if (ac == 2 && str_isequal(av[1], "-h", true)) {
        my_printf("USAGE\n./corewar [-dump nbr_cycle] ");
        my_printf("[[-n prog_number] [-a load_address] prog_name] ...\n");
        my_printf("DESCRIPTION\n");
        my_printf("-dump nbr_cycle dumps the memory ");
        my_printf("after the nbr_cycle execution (if the round isn't\n");
        my_printf("already over) with the following ");
        my_printf("format: 32 bytes/line\n");
        my_printf("in hexadecimal (A0BCDEFE1DD3...)\n");
        my_printf("-n prog_number sets the next program's ");
        my_printf("number. By default, the first free number\n");
        my_printf("in the parameter order\n");
        my_printf("-a load_address sets the next program's ");
        my_printf("loading address. When no address is\n");
        my_printf("specified, optimize the addresses ");
        my_printf("so that the processes are as far\n");
        my_printf("away from each other as possible. ");
        my_printf("The addresses are MEM_SIZE modulo.\n");
        exit(0);
    }
}

void error_handling(int ac, char **av)
{
    if (ac == 1)
        exit(84);
    help_display(ac, av);
}
