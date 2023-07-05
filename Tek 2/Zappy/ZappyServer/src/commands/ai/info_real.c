/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** commands1
*/

#include "server.h"

void broadcast_r(PARAMS_FEATS, int fd)
{
    dprintf(fd, "Broadcast\n");
    remove_command(&s->cmd, "Broadcast", fd);
}

void connect_nbr_r(PARAMS_FEATS, int fd)
{
    clients_t *player = find_item(s->clients, fd);
    int team_pos = find_team(s->nameX, player->name_team);
    int clientNb = s->players_in_teams[team_pos];
    dprintf(fd, "%d\n", clientNb);
    remove_command(&s->cmd, "Connect_nbr", fd);
}

void look_r(PARAMS_FEATS, int fd)
{
    clients_t *player = find_item(s->clients, fd);
    char *looked_string = NULL;
    looked_string = generate_looked_string(s->tiles, player->lv);
    add_space(looked_string);
    dprintf(fd, "%s\n", looked_string);
    free(looked_string);
    remove_command(&s->cmd, "Look", fd);
}

void inventory_r(PARAMS_FEATS, int fd)
{
    char invent[200];
    clients_t *player = find_item(s->clients, fd);
    sprintf(invent, "[ linemate %d, deraumere %d, sibur %d, mendiane %d, \
phiras %d, thystame %d, food %d ]\n", player->inv->linemate,
    player->inv->deraumere, player->inv->sibur, player->inv->mendiane,
    player->inv->phiras, player->inv->thystame, player->inv->food);
    dprintf(fd, "%s", invent);
    remove_command(&s->cmd, "Inventory", fd);
}
