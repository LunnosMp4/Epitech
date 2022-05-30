/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** main.c
*/

#include "asm.h"

int main(int ac, char **av)
{
    char *str = NULL;
    header_t *header = init_header();
    assembler_t *assem = init_assembler(av[1]);
    info_file_t *info = init_file(av[1]);

    if (ac == 2 && str_isequal(av[1], "-h", true)) {
        asm_usage();
        return 0;
    }
    if (ac == 2) {
        parsing_file(info, header);
        str = parse_file(av[1]);
        parsing_asm(assem, header);
        parsing(assem, str);
    }
    close(assem->fd2);
    free(header);
    free(assem);
    free(info);
    return EXIT_SUCCESS;
}

void parsing(assembler_t *assem, char *str)
{
    char **arr = my_str_to_word_array(str, "#\n");

    for (int i = 0; arr[i]; i++) {
        parsing3(assem, arr[i]);
        parsing4(assem);
    }
}

void parsing3(assembler_t *assm, char *str)
{
    assm->arr_2d = my_str_to_word_array(str, " ,");

    if (str_isequal(assm->arr_2d[0], LIVE, true))
        parsing_live(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], LD, true))
        parsing_ld(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], ST, true))
        parsing_st(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], ADD, true))
        parsing_add(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], SUB, true))
        parsing_sub(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], AND, true))
        parsing_and(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], OR, true))
        parsing_or(assm->arr_2d, assm);
}

void parsing4(assembler_t *assm)
{
    if (str_isequal(assm->arr_2d[0], XOR, true))
        parsing_xor(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], ZJMP, true))
        parsing_zjmp(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], LDI, true))
        parsing_ldi(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], STI, true))
        parsing_sti(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], FORK, true))
        parsing_fork(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], LLD, true))
        parsing_lld(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], LLDI, true))
        parsing_lldi(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], LFORK, true))
        parsing_lfork(assm->arr_2d, assm);
    if (str_isequal(assm->arr_2d[0], AFF, true))
        parsing_aff(assm->arr_2d, assm);
}
