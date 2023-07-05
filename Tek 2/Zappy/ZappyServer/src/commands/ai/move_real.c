/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** commands1
*/

#include "server.h"

void forward_r(PARAMS_FEATS, int fd)
{
    clients_t *temp = find_item(s->clients, fd);
    if (temp->orientation == 1) {
        temp->y--;
        temp->y = forward_north(temp->y, s->height);
    }
    if (temp->orientation == 3) {
        temp->y++;
        temp->y = forward_south(temp->y, s->height);
    }
    if (temp->orientation == 2) {
        temp->x++;
        temp->x = forward_east(temp->x, s->width);
    }
    if (temp->orientation == 4) {
        temp->x--;
        temp->x = forward_west(temp->x, s->width);
    }
    dprintf(fd, "ok\n");
    gui_commands[9](s, temp);
    remove_command(&s->cmd, "Forward", fd);
}

void right_r(PARAMS_FEATS, int fd)
{
    clients_t *temp = find_item(s->clients, fd);
    if (temp->orientation == 4)
        temp->orientation = 1;
    else
        temp->orientation++;
    dprintf(fd, "ok\n");
    gui_commands[9](s, temp);
    remove_command(&s->cmd, "Right", fd);
}

void left_r(PARAMS_FEATS, int fd)
{
    clients_t *temp = find_item(s->clients, fd);
    if (temp->orientation == 1)
        temp->orientation = 4;
    else
        temp->orientation--;
    dprintf(fd, "ok\n");
    gui_commands[9](s, temp);
    remove_command(&s->cmd, "Left", fd);
}
