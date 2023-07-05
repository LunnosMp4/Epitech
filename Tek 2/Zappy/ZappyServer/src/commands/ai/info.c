/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** commands1
*/

#include "server.h"

void broadcast(PARAMS_FEATS)
{
    if (command_args_good_info("Broadcast",
    copy_double_array(s->client->request->args, 1))) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        add_cmd(&s->cmd, "Broadcast", s->client->request->args,
        s->client->sockfd, current_time, 0);
    }
}

void connect_nbr(PARAMS_FEATS)
{
    if (command_args_good_info("Connect_nbr",
    copy_double_array(s->client->request->args, 1))) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        add_cmd(&s->cmd, "Connect_nbr",
        s->client->request->args, s->client->sockfd,
        current_time, 7 / s->freq);
    }
}

void look(PARAMS_FEATS)
{
    if (command_args_good_info("Look",
    copy_double_array(s->client->request->args, 1))) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        add_cmd(&s->cmd, "Look", s->client->request->args,
        s->client->sockfd, current_time, 7 / s->freq);
    }
}

void inventory(PARAMS_FEATS)
{
    if (command_args_good_info("Inventory",
    copy_double_array(s->client->request->args, 1))) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        add_cmd(&s->cmd, "Inventory",
        s->client->request->args, s->client->sockfd,
        current_time, 7 / s->freq);
    }
}
