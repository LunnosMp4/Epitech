/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** commands3
*/

#include "server.h"

void set(PARAMS_FEATS)
{
    if (command_args_good_extra("Set",
    copy_double_array(s->client->request->args, 1))) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        add_cmd(&s->cmd, "Set", s->client->request->args, s->client->sockfd,
        current_time, 7 / s->freq);
    } else
        dprintf(s->client->sockfd, "ko\n");
}

void fork_f(PARAMS_FEATS)
{
    if (command_args_good_extra("Fork",
    copy_double_array(s->client->request->args, 1))) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        add_cmd(&s->cmd, "Fork", s->client->request->args,
        s->client->sockfd, current_time, 42 / s->freq);
    }
}

void incantation(PARAMS_FEATS)
{
    if (command_args_good_extra("Incantation",
    copy_double_array(s->client->request->args, 1)) &&
    can_incantation(s, s->client, s->tiles)) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        dprintf(s->client->sockfd, "Elevation underway\n");
        add_cmd(&s->cmd, "Incantation",
        s->client->request->args, s->client->sockfd,
        current_time, 300 / s->freq);
    } else
        dprintf(s->client->sockfd, "ko\n");
}

void eject(PARAMS_FEATS)
{
    if (command_args_good_extra("Eject",
    copy_double_array(s->client->request->args, 1))) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        add_cmd(&s->cmd, "Eject", s->client->request->args,
        s->client->sockfd, current_time, 7 / s->freq);
    } else
        dprintf(s->client->sockfd, "ko\n");
}

void take(PARAMS_FEATS)
{
    if (command_args_good_extra("Take",
    copy_double_array(s->client->request->args, 1))) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        add_cmd(&s->cmd, "Take", s->client->request->args, s->client->sockfd,
        current_time, 7 / s->freq);
    } else
        dprintf(s->client->sockfd, "ko\n");
}
