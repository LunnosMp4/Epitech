/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** create_channel.c
*/

#include "server.h"

static bool check_params(int nb_args, char **args)
{
    if (nb_args != 2)
        return false;
    if (strlen(args[0]) > MAX_NAME_LENGTH)
        return false;
    if (strlen(args[1]) > MAX_DESCRIPTION_LENGTH)
        return false;
    return true;
}

void create_channel(PARAMS_FEATS)
{
    if (!check_params(s->client->request->nb_args,
    s->client->request->args)) {
        dprintf(FD, "200 BWA Bad request\r\n");
        return;
    }
    char *args[2] = {s->client->request->args[0], s->client->request->args[1]};
    char channel_uuid[37];
    if (find_channel_by_name(s->channels, args[0]) != NULL) {
        dprintf(FD, "211 BWA Channel Already Exist\r\n");
        return;
    }
    uuid_t uuid;
    uuid_generate(uuid);
    uuid_unparse(uuid, channel_uuid);
    s->channels = add_channel(s->channels, args, uuid,
    find_team_by_uuid(s->teams, s->client->request->uuid_team));
    server_event_channel_created(s->client->request->uuid_team,
    channel_uuid, args[0]);
    dprintf(FD, "111 BWA Channel created BWA \"%s\" \"%s\" \"%s\"\r\n",
        channel_uuid, args[0], args[1]);
}
