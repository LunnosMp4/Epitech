/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** info_channel.c
*/

#include "server.h"

void info_channel(PARAMS_FEATS)
{
    channels_t *channel = find_channel_by_uuid(s->channels,
    s->client->request->uuid_channel);
    dprintf(FD, "112 BWA Channel info BWA \"%s\" \"%s\" \"%s\"\r\n",
    s->client->request->uuid_channel, channel->name, channel->description);
}
