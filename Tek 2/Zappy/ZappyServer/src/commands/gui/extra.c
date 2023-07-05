/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** extra.c
*/

#include "server.h"

void msz(PARAMS_FEATS, clients_t *current)
{
    current = current;
    dprintf(s->gui_fd, "msz %d %d\n", s->width, s->height);
}

void sgt(PARAMS_FEATS, clients_t *current)
{
    current = current;
    dprintf(s->gui_fd, "sgt %d\n", s->freq);
}

void plv(PARAMS_FEATS, clients_t *current)
{
    int id = atoi(current->request->args[1]);
    clients_t *player = find_id(s->clients, id);
    dprintf(s->gui_fd, "plv %d %d\n", player->number, player->lv);
}

void sst(PARAMS_FEATS, clients_t *current)
{
    s->freq = atoi(current->request->args[1]);
    dprintf(s->gui_fd, "sst %d\n", s->freq);
}
