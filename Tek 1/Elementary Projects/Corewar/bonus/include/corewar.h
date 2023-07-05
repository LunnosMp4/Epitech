/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** corewar.h
*/

#ifndef COREWAR_H
    #define COREWAR_H
    #include "my.h"

typedef struct process_s {
	int	nb_process;
    int pos_process;
	int	is_alive;
	int	carry;
    int cycle;
    int	pc;
    struct process_s *next;
    struct process_s *child;
} process_t;

typedef struct champion_s {
    char *hex_code;
    int nb_live;
    bool is_alive;
    int id;
    process_t *process;
    header_t *header;
} champion_t;

typedef struct lnk_list_s {
    champion_t *champ;
    struct lnk_list_s *next;
} lnk_list_t;

typedef struct corewar_s {
    int *nb;
    char *arena;
    char *final_arena;
    int cycle;
    int cycle_to_die;
    int last_cycle_check;
    int last_live;
    int dump_max;
    int nb_live;
    int nb_check;
    lnk_list_t *champs;
} corewar_t;

//Linked list
void add_node(champion_t *champ, lnk_list_t **head);
void delete_node(lnk_list_t **head);
void print_list(lnk_list_t *node);

corewar_t *init_corewar(void);
void init_arena(corewar_t *corewar, int ac);
void error_handling(int ac, char **av);
void check_cor(int ac, char **av, corewar_t *corewar);
void open_file(int ac, char **av, corewar_t *corewar);
champion_t *read_cor(char *path);
char *my_arenacpy(char *dest, char *src, int max_size);
void run_vm(corewar_t *corewar);
void execute_instruction(corewar_t *corewar,
champion_t *champ, process_t *process);
int	modulo_op(int nb, int modulo);
void change_carry(process_t *process);
void print_win(lnk_list_t *champs);
void print_win_last(corewar_t *corewar, lnk_list_t *champs);

//Instruction
void do_live(corewar_t *corewar, champion_t *champ, process_t *process);
void do_ld(corewar_t *corewar, champion_t *champ, process_t *process);
void do_zjmp(corewar_t *corewar, champion_t *champ, process_t *process);
void do_st(corewar_t *corewar, champion_t *champ, process_t *process);
void do_add(corewar_t *corewar, champion_t *champ, process_t *process);
void do_sub(corewar_t *corewar, champion_t *champ, process_t *process);
void do_and(corewar_t *corewar, champion_t *champ, process_t *process);
void do_or(corewar_t *corewar, champion_t *champ, process_t *process);
void do_xor(corewar_t *corewar, champion_t *champ, process_t *process);
void do_ldi(corewar_t *corewar, champion_t *champ, process_t *process);
void do_sti(corewar_t *corewar, champion_t *champ, process_t *process);
void do_fork(corewar_t *corewar, champion_t *champ, process_t *process);
void do_lld(corewar_t *corewar, champion_t *champ, process_t *process);
void do_lldi(corewar_t *corewar, champion_t *champ, process_t *process);
void do_lfork(corewar_t *corewar, champion_t *champ, process_t *process);
void do_aff(corewar_t *corewar, champion_t *champ, process_t *process);

#endif
