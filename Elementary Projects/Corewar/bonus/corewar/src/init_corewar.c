/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** init_corewar.c
*/

#include "corewar.h"

corewar_t *init_corewar(void)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    corewar->champs = NULL;
    corewar->arena = NULL;
    corewar->final_arena = NULL;
    corewar->nb = NULL;
    return corewar;
}

static int count_champ(int *nb, int ac)
{
    int count = 0;

    for (int i = 0; i < ac; i++)
        if (nb[i] == 1)
            count++;
    if (count > 4)
        exit(84);
    return count;
}

static void convert_cor_to_hex(int nbr, char const *base, corewar_t *corewar)
{
    static int i = 0;

    if (nbr < 0)
        nbr += 256;
    if (nbr != 0)
        corewar->final_arena[i++] = base[nbr / 16];
    corewar->final_arena[i++] = base[nbr % 16];
}

void init_arena(corewar_t *corewar, int ac)
{
    corewar->arena = malloc(sizeof(char) * MEM_SIZE);
    corewar->final_arena = malloc(sizeof(char) * MEM_SIZE * 2);
    lnk_list_t *tmp = corewar->champs;
    int nb_champ = count_champ(corewar->nb, ac);

    for (int i = 0; i < MEM_SIZE &&
    tmp; i += MEM_SIZE / nb_champ) {
        if (i != 0)
            i -= tmp->champ->header->prog_size;
        my_arenacpy(corewar->arena + i,
        tmp->champ->hex_code, tmp->champ->header->prog_size);
        tmp = tmp->next;
    }
    for (int j = 0; j <= MEM_SIZE; j++)
        convert_cor_to_hex(corewar->arena[j], "0123456789abcdef", corewar);
}
