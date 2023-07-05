/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** real_commands
*/

#include "server.h"

void check_commands_up(server_t *s)
{
    commands_order_t *current = s->cmd;
    struct timeval current_time;
    double elapsed_seconds;
    while (current != NULL) {
        gettimeofday(&current_time, NULL);
        elapsed_seconds = current_time.tv_sec - current->asked_timer.tv_sec;
        if (elapsed_seconds >= current->good_time) {
            int code = which_command(current->command);
            real_commands[code - 1](s, current->fd);
        }
        current = current->next;
    }
}
