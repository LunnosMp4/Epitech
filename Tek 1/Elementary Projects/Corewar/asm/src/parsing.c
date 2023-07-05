/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** parsing
*/

#include "asm.h"

void parsing_instructions(assembler_t *assm, header_t *header);

char *parsing_name(assembler_t *assm)
{
    lseek(assm->fd, (off_t)0, SEEK_SET);
    assm->buffer_name = malloc(sizeof(char) * (assm->size_name + 1));
    read(assm->fd, assm->buffer_name, assm->size_name);
    if (assm->fd < 0)
        exit(89);
    assm->buffer_name[assm->size_name] = '\0';
    assm->arr_name = my_str_to_word_array(assm->buffer_name, ",#\n");
    for (int i = 0; assm->arr_name[i] != NULL; i++)
        if (my_strstr(assm->arr_name[i], NAME_CMD_STRING))
            assm->name = assm->arr_name[i];
    for (; assm->name[assm->j_name] != '"'; assm->name++);
    assm->name++;
    for (; assm->name[assm->j_name]; assm->j_name++)
        if (assm->name[assm->j_name] == '"')
            assm->name[assm->j_name] = '\0';
    free(assm->buffer_name);
    return assm->name;
}

char *parsing_comment(assembler_t *assm)
{
    lseek(assm->fd, (off_t)0, SEEK_SET);
    assm->buffer_comment = malloc(sizeof(char) * (assm->size_comment + 1));
    read(assm->fd, assm->buffer_comment, assm->size_comment);
    assm->buffer_comment[assm->size_comment] = '\0';
    assm->arr_comment = my_str_to_word_array(assm->buffer_comment, ",\n\t");
    for (int i = 0; assm->arr_comment[i] != NULL; i++)
        if (my_strstr(assm->arr_comment[i], COMMENT_CMD_STRING))
            assm->comment = assm->arr_comment[i];
    for (; assm->comment[assm->j_comment] != '"'; assm->comment++);
    assm->comment++;
    for (; assm->comment[assm->j_comment]; assm->j_comment++)
        if (assm->comment[assm->j_comment] == '"')
            assm->comment[assm->j_comment] = '\0';
    free(assm->buffer_comment);
    close(assm->fd);
    return assm->comment;
}

void parsing_asm(assembler_t *assm, header_t *header)
{
    char *name = NULL;
    int fill = 0;

    my_strcpy(header->prog_name, parsing_name(assm));
    my_strcpy(header->comment, parsing_comment(assm));
    name = my_strcat(my_strdup(header->prog_name), ".cor");
    my_strcat(my_strdup(header->comment), ".cor");
    assm->fd2 = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
    write(assm->fd2, &header->magic, sizeof(header->magic));
    write(assm->fd2, header->prog_name, PROG_NAME_LENGTH);
    write(assm->fd2, &fill, sizeof(int));
    write(assm->fd2, &header->prog_size, sizeof(int));
    write(assm->fd2, header->comment, COMMENT_LENGTH);
    write(assm->fd2, &fill, sizeof(int));
}
