/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** list_channel.c
*/

#include "server.h"

void list_channel(PARAMS_FEATS)
{
    uuid_t uuid_team;
    char *names_channels = NULL;
    uuid_parse(s->client->request->uuid_team, uuid_team);

    for (channels_t *tmp = s->channels; tmp; tmp = tmp->next)
        if (!uuid_compare(tmp->team->uuid, uuid_team)) {
            printf("Channel name: %s\n", tmp->name);
            names_channels = str_append(names_channels, tmp->name);
            printf("Channel names: %s\n", names_channels);
        }
    printf("Channel names: %s\n", names_channels);

    dprintf(FD, "113 %s\r\n", names_channels);
}
