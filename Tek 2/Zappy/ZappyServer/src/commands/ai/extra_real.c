/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** commands3
*/

#include "server.h"

void set_r(PARAMS_FEATS, int fd)
{
    clients_t *player = find_item(s->clients, fd);
    map_t *current_map = find_map(s->tiles, player->x, player->y);
    int item = -1;
    if ((item = has_item_set(player, s->cmd)) != -1) {
        drop_item(&player, &current_map, item);
        dprintf(fd, "ok\n");
        gui_commands[7](s, player);
        player->request = malloc(sizeof(request_t));
        player->request->args = malloc(sizeof(char *) * 3);
        player->request->args[0] = strdup(to_string(current_map->x));
        player->request->args[1] = strdup(to_string(current_map->y));
        player->request->args[3] = NULL;
        gui_commands[8](s, player);
        free(player->request->args[0]);
        free(player->request->args[1]);
        free(player->request->args);
        free(player->request);
    }
    remove_command(&s->cmd, "Set", fd);
}

void fork_r(PARAMS_FEATS, int fd)
{
    dprintf(fd, "ok\n");
    remove_command(&s->cmd, "Fork", fd);
}

void incantation_r(PARAMS_FEATS, int fd)
{
    int max_lv = 8;

    if (s->client->lv > 0 || s->client->lv + 1 <= max_lv)
        s->client->lv = s->client->lv + 1;
    dprintf(fd, "Current level: %d\n", s->client->lv);
    remove_command(&s->cmd, "Incantation", fd);
}

void eject_r(PARAMS_FEATS, int fd)
{
    dprintf(fd, "Eject\n");
    remove_command(&s->cmd, "Eject", fd);
}

void take_r(PARAMS_FEATS, int fd)
{
    clients_t *player = find_item(s->clients, fd);
    map_t *current_map = find_map(s->tiles, player->x, player->y);
    int item = -1;
    if ((item = has_item_take(current_map, s->cmd)) != -1) {
        take_item(&player, &current_map, item);
        dprintf(fd, "ok\n");
        gui_commands[7](s, player);
        player->request = malloc(sizeof(request_t));
        player->request->args = malloc(sizeof(char *) * 3);
        player->request->args[0] = strdup(to_string(current_map->x));
        player->request->args[1] = strdup(to_string(current_map->y));
        player->request->args[3] = NULL;
        gui_commands[8](s, player);
        free(player->request->args[0]);
        free(player->request->args[1]);
        free(player->request->args);
        free(player->request);
    }
    remove_command(&s->cmd, "Take", fd);
}
