/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** asm.h
*/

#ifndef ASM_H
    #define ASM_H
    #include "my.h"

    #define LIVE "live"
    #define LD "ld"
    #define ST "st"
    #define ADD "add"
    #define SUB "sub"
    #define AND "and"
    #define OR "or"
    #define XOR "xor"
    #define ZJMP "zjmp"
    #define LDI "ldi"
    #define STI "sti"
    #define FORK "fork"
    #define LLD "lld"
    #define LLDI "lldi"
    #define LFORK "lfork"
    #define AFF "aff"

extern op_t op_tab[];
typedef struct assembler_s {
    int fd;
    char *str;

    int j_name;
    char *name;
    char *buffer_name;
    int size_name;
    char **arr_name;

    int j_comment;
    char *comment;
    char *buffer_comment;
    int size_comment;
    char **arr_comment;

    char **arr_2d;
    int fd2;
} assembler_t;

typedef struct info_file_s {
    int fd;
    int size;
    char *buffer;
    char **arr;
    int check_live;
} info_file_t;

// !INIT_STRUCT
assembler_t *init_assembler(char *str);
header_t *init_header(void);
info_file_t *init_file(char *str);

void asm_usage(void);
char *read_file(char *str);
char *parse_file(char *str);
void parsing_file(info_file_t *info, header_t *header);
void error_instructions(info_file_t *info, char *str, header_t *header);
void error_instructions2(header_t *header, char **arr);
int count(char const *str, char ch);

// !PARSING
void parsing(assembler_t *assem, char *str);
void parsing3(assembler_t *assm, char *str);
void parsing4(assembler_t *assm);
void parsing_asm(assembler_t *assm, header_t *header);
char *parsing_name(assembler_t *assm);
char *parsing_comment(assembler_t *assm);
void byte_shifting(header_t *header);
int coding_byte(char **arr);
int keep_value(char *str);
void check_arg(char **arr, char *str, int i);

int is_register(char *str);
int is_indirect(char *str);
int is_direct(char *str);
int is_label(char *str);

int binary_to_decimal(char *str);

// !PARSING INSTRUCTIONS
void parsing_and(char **arr, assembler_t *assem);
void parsing_live(char **arr, assembler_t *assem);
void parsing_add(char **arr, assembler_t *assem);
void parsing_aff(char **arr, assembler_t *assem);
void parsing_fork(char **arr, assembler_t *assem);
void parsing_ld(char **arr, assembler_t *assem);
void parsing_ldi(char **arr, assembler_t *assem);
void parsing_lfork(char **arr, assembler_t *assem);
void parsing_lld(char **arr, assembler_t *assem);
void parsing_lldi(char **arr, assembler_t *assem);
void parsing_or(char **arr, assembler_t *assem);
void parsing_st(char **arr, assembler_t *assem);
void parsing_sti(char **arr, assembler_t *assem);
void parsing_sub(char **arr, assembler_t *assem);
void parsing_xor(char **arr, assembler_t *assem);
void parsing_zjmp(char **arr, assembler_t *assem);

// !PROG_SIZE
void count_live(info_file_t *info, header_t *header, char **arr);
void count_ld(header_t *header, char **arr);
void count_st(header_t *header, char **arr);
void count_add(header_t *header, char **arr);
void count_sub(header_t *header, char **arr);
void count_and(header_t *header, char **arr);
void count_or(header_t *header, char **arr);
void count_xor(header_t *header, char **arr);
void count_zjmp(header_t *header, char **arr);
void count_ldi(header_t *header, char **arr);
void count_sti(header_t *header, char **arr);
void count_fork(header_t *header, char **arr);
void count_lld(header_t *header, char **arr);
void count_lldi(header_t *header, char **arr);
void count_lfork(header_t *header, char **arr);
void count_aff(header_t *header, char **arr);

#endif
