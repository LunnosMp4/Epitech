/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** init_structs
*/

#include "asm.h"

header_t *init_header(void)
{
    header_t *header = malloc(sizeof(header_t));

    my_memset(header, 0, sizeof(header_t));
    byte_shifting(header);
    header->prog_size = 0;
    return header;
}

assembler_t *init_assembler(char *str)
{
    assembler_t *assem = malloc(sizeof(assembler_t));

    assem->fd = open(str, O_RDONLY);
    assem->str = str;
    assem->j_name = 0;
    assem->name = malloc(sizeof(char) * 1000);
    assem->buffer_name = NULL;
    assem->size_name = lseek(assem->fd, (off_t)0, SEEK_END);
    assem->arr_name = NULL;
    assem->j_comment = 0;
    assem->comment = malloc(sizeof(char) * 1000);
    assem->buffer_comment = NULL;
    assem->size_comment = lseek(assem->fd, (off_t)0, SEEK_END);
    assem->arr_comment = NULL;
    assem->arr_2d = NULL;
    assem->fd2 = 0;

    return assem;
}

info_file_t *init_file(char *str)
{
    info_file_t *info = malloc(sizeof(info_file_t));

    info->check_live = 0;
    info->fd = open(str, O_RDONLY);
    if (info->fd == -1)
        exit(84);
    info->size = lseek(info->fd, 0, SEEK_END);
    if (info->size == -1)
        exit(84);
    info->buffer = malloc(sizeof(char) * (info->size + 1));
    if (!info->buffer)
        return NULL;
    lseek(info->fd, 0, SEEK_SET);
    if (read(info->fd, info->buffer, info->size) == -1)
        exit(84);
    info->buffer[info->size] = '\0';
    info->arr = my_str_to_word_array(info->buffer, "\n");
    return info;
}

void byte_shifting(header_t *header)
{
    header->magic = COREWAR_EXEC_MAGIC;
    u_int32_t b0;
    u_int32_t b1;
    u_int32_t b2;
    u_int32_t b3;
    u_int32_t res;

    b0 = (header->magic & 0x000000FF) << 24u;
    b1 = (header->magic & 0x0000FF00) << 8u;
    b2 = (header->magic & 0x00FF0000) >> 8u;
    b3 = (header->magic & 0xFF000000) >> 24u;

    res = b0 | b1 | b2 | b3;
    header->magic = res;
}
