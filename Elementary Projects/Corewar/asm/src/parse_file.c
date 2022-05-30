/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** parse_file
*/

#include "asm.h"

char *parse_file(char *str)
{
    int j = 0;
    int fd = open(str, O_RDONLY);
    char *buffer = NULL;
    char *new_str = NULL;
    int size = lseek(fd, 0, SEEK_END);

    lseek(fd, 0, SEEK_SET);
    buffer = malloc(sizeof(char) * (size + 1));
    new_str = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    buffer[size] = '\0';
    for (int i = 0; buffer[i]; i++, j++) {
        if (buffer[i] == '#') while (buffer[i] != '\n') i++;
        new_str[j] = buffer[i];
    }
    new_str[j] = '\0';
    return new_str;
}

void parsing_file(info_file_t *info, UNUSED header_t *header)
{
    int name = 0;
    int comment = 0;

    for (int i = 0; info->arr[i]; i++) {
        if (my_strstr(info->arr[i], NAME_CMD_STRING))
            name = 1;
        if (my_strstr(info->arr[i], COMMENT_CMD_STRING))
            comment = 1;
    }
    if (name == 0 || comment == 0) {
        my_printf("Missing .name or .comment in the header.\n");
        exit(84);
    }
    for (int j = 0; info->arr[j]; j++)
        error_instructions(info, info->arr[j], header);
    if (info->check_live == 0) {
        my_printf("Missing live instruction.\n");
        exit(84);
    }
}

void error_instructions(info_file_t *info, char *str, header_t *header)
{
    char **arr = my_str_to_word_array(str, " ,");

    if (str_isequal(arr[0], LIVE, true))
        count_live(info, header, arr);
    if (str_isequal(arr[0], LD, true))
        count_ld(header, arr);
    if (str_isequal(arr[0], ST, true))
        count_st(header, arr);
    if (str_isequal(arr[0], ADD, true))
        count_add(header, arr);
    if (str_isequal(arr[0], SUB, true))
        count_sub(header, arr);
    if (str_isequal(arr[0], AND, true))
        count_and(header, arr);
    if (str_isequal(arr[0], OR, true))
        count_or(header, arr);
    error_instructions2(header, arr);
}

void error_instructions2(header_t *header, char **arr)
{
    if (str_isequal(arr[0], XOR, true))
        count_xor(header, arr);
    if (str_isequal(arr[0], ZJMP, true))
        count_zjmp(header, arr);
    if (str_isequal(arr[0], LDI, true))
        count_ldi(header, arr);
    if (str_isequal(arr[0], STI, true))
        count_sti(header, arr);
    if (str_isequal(arr[0], FORK, true))
        count_fork(header, arr);
    if (str_isequal(arr[0], LLD, true))
        count_lld(header, arr);
    if (str_isequal(arr[0], LLDI, true))
        count_lldi(header, arr);
    if (str_isequal(arr[0], LFORK, true))
        count_lfork(header, arr);
    if (str_isequal(arr[0], AFF, true))
        count_aff(header, arr);
}
