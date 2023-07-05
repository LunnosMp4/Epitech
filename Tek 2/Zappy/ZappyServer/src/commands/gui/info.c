/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** info
*/

#include "server.h"

void pnw(PARAMS_FEATS, clients_t *current)
{
    dprintf(s->gui_fd, "pnw %d %d %d %d %d %s",
    current->number, current->x, current->y, current->orientation,
    current->lv,current->name_team);
}

void bct(PARAMS_FEATS, clients_t *current)
{
    if (current->request->args[0] == NULL ||
    current->request->args[1] == NULL)
        return;
    map_t *found_tile = find_which_tile(s->tiles,
    atoi(current->request->args[0]),
    atoi(current->request->args[1]));
    dprintf(s->gui_fd, "bct %d %d %d %d %d %d %d %d %d\n",
    found_tile->x, found_tile->y, found_tile->food, found_tile->linemate,
    found_tile->deraumere, found_tile->sibur,
    found_tile->mendiane, found_tile->phiras, found_tile->thystame);
}

void mct(PARAMS_FEATS, clients_t *current)
{
    current->request = malloc(sizeof(request_t));
    current->request->args = malloc(sizeof(char*) * 3);
    for (int i = 0; i != s->height; i++) {
        for (int j = 0; j != s->width; j++) {
            current->request->args[0] = strdup(to_string(j));
            current->request->args[1] = strdup(to_string(i));
            current->request->args[2] = NULL;
            bct(s, current);
            current->request->args[0][0] = '\0';
            current->request->args[1][0] = '\0';
        }
    }
    free(current->request->args[0]);
    free(current->request->args[1]);
    free(current->request->args);
    free(current->request);
}

void tna(PARAMS_FEATS, clients_t *current)
{
    current = current;
    for (int i = 0; s->nameX[i] != NULL; i++) {
        dprintf(s->gui_fd, "tna %s\n", s->nameX[i]);
    }
}

void pin(PARAMS_FEATS, clients_t *current)
{
    int id = atoi(current->request->args[1]);
    clients_t *player = find_id(s->clients, id);
    dprintf(s->gui_fd, "pin %d %d %d %d %d %d %d %d %d %d\n",
    player->number,
    player->x, player->y, player->inv->food, player->inv->linemate,
    player->inv->deraumere, player->inv->sibur,
    player->inv->mendiane, player->inv->phiras, player->inv->thystame);
}
