/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** read_file.c
*/

#include "corewar.h"

int swap_endian(uint32_t enderman)
{
    uint32_t b0;
    uint32_t b1;
    uint32_t b2;
    uint32_t b3;
    uint32_t res;

    b0 = (enderman & 0x000000ff) << 24u;
    b1 = (enderman & 0x0000ff00) << 8u;
    b2 = (enderman & 0x00ff0000) >> 8u;
    b3 = (enderman & 0xff000000) >> 24u;

    res = b0 | b1 | b2 | b3;
    return res;
}

process_t *process(void)
{
    process_t *process = malloc(sizeof(process_t));
    process->pc = 0;
    process->carry = 0;
    process->nb_process = 0;
    process->cycle = 0;
    process->pos_process = 0;
    return process;
}

champion_t *read_cor(char *path)
{
    int fd = open(path, O_RDONLY);
    champion_t *champ = malloc(sizeof(champion_t));
    champ->process = malloc(sizeof(process_t));
    static int id = 0;

    champ->header = malloc(sizeof(header_t));
    if (fd == -1)
        exit(84);
    read(fd, champ->header, sizeof(header_t));
    champ->header->magic = swap_endian(champ->header->magic);
    champ->header->prog_size = swap_endian(champ->header->prog_size);
    champ->hex_code = malloc(sizeof(char) * champ->header->prog_size);
    read(fd, champ->hex_code, champ->header->prog_size);
    champ->nb_live = 0;
    champ->is_alive = true;
    champ->id = id++;
    champ->process = process();
    close(fd);
    return champ;
}
