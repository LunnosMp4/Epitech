/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** commands1
*/

#include "server.h"

void forward(PARAMS_FEATS)
{
    if (command_args_good_move("Forward",
    copy_double_array(s->client->request->args, 1))) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        add_cmd(&s->cmd, "Forward", s->client->request->args,
        s->client->sockfd, current_time, (7 / s->freq) * 1.1);
    }
}

void right(PARAMS_FEATS)
{
    if (command_args_good_move("Right",
    copy_double_array(s->client->request->args, 1))) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        add_cmd(&s->cmd, "Right", s->client->request->args,
        s->client->sockfd, current_time, (7 / s->freq) * 1.1);
    }
}

void left(PARAMS_FEATS)
{
    if (command_args_good_move("Left",
    copy_double_array(s->client->request->args, 1))) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        add_cmd(&s->cmd, "Left", s->client->request->args,
        s->client->sockfd, current_time, (7 / s->freq) * 1.1);
    }
}
