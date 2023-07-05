/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** use.c
*/

#include "server.h"

static void select_team(server_t *s)
{
    if (find_team_by_uuid(s->teams, s->client->request->args[0]) != NULL) {
        s->client->request->uuid_team = s->client->request->args[0];
        s->client->request->context = CTX_TEAM;
        dprintf(FD, "108 BWA Team selected\r\n");
    } else
        dprintf(FD, "208 BWA Unknow Team BWA \"%s\"\r\n",
        s->client->request->args[0]);
    return;
}

static void select_channel(server_t *s)
{
    if (find_team_by_uuid(s->teams, s->client->request->args[0]) == NULL) {
        dprintf(FD, "208 BWA Unknow Team BWA \"%s\"\r\n",
        s->client->request->args[0]);
        return;
    }
    if (find_channel_by_uuid(s->channels,
    s->client->request->args[1]) != NULL) {
        s->client->request->uuid_team = s->client->request->args[0];
        s->client->request->uuid_channel = s->client->request->args[1];
        s->client->request->context = CTX_TEAM_CHANNEL;
        dprintf(FD, "108 BWA Channel selected\r\n");
    } else
        dprintf(FD, "208 BWA Unknow Channel BWA \"%s\"\r\n",
        s->client->request->args[1]);
    return;
}

static void select_thread(server_t *s)
{
    if (find_team_by_uuid(s->teams, s->client->request->args[0]) == NULL) {
        dprintf(FD, "208 BWA Unknow Team BWA \"%s\"\r\n",
        s->client->request->args[0]);
        return;
    }
    if (find_channel_by_uuid(s->channels,
    s->client->request->args[1]) == NULL) {
        dprintf(FD, "208 BWA Unknow Channel BWA \"%s\"\r\n",
        s->client->request->args[1]);
        return;
    }
    if (find_thread_by_uuid(s->threads, s->client->request->args[2]) != NULL) {
        s->client->request->uuid_team = s->client->request->args[0];
        s->client->request->uuid_channel = s->client->request->args[1];
        s->client->request->uuid_thread = s->client->request->args[2];
        s->client->request->context = CTX_TEAM_CHANNEL_THREAD;
        dprintf(FD, "108 BWA Thread selected\r\n");
    } else
        dprintf(FD, "208 BWA Unknow Thread BWA \"%s\"\r\n",
        s->client->request->args[2]);
}

static void change_context(server_t *s, int nb_arg)
{
    if (nb_arg == 1)
        select_team(s);
    if (nb_arg == 2)
        select_channel(s);
    if (nb_arg == 3)
        select_thread(s);
}

void use(PARAMS_FEATS)
{
    if (s->client->request->args == NULL || (s->client->request->nb_args < 1 ||
    s->client->request->nb_args > 3)) {
        dprintf(FD, "200 BWA Bad request\r\n");
        return;
    }
    change_context(s, s->client->request->nb_args);
}
