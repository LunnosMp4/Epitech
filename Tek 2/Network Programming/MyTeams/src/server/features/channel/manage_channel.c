/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** manage_channel.c
*/

#include "server.h"

channels_t *add_channel(channels_t *list, char **args,
uuid_t uuid, teams_t *team)
{
    channels_t *new_channel = malloc(sizeof(channels_t));
    new_channel->name = args[0];
    new_channel->description = args[1];
    memcpy(new_channel->uuid, uuid, sizeof(uuid_t));
    new_channel->team = team;
    new_channel->next = list;
    list = new_channel;
    return new_channel;
}

void remove_channel(channels_t *list, channels_t *channel)
{
    channels_t *prev_channel = NULL;
    channels_t *curr_channel = list;
    while (curr_channel != NULL && curr_channel != channel) {
        prev_channel = curr_channel;
        curr_channel = curr_channel->next;
    }
    if (curr_channel == channel) {
        if (prev_channel != NULL) {
            prev_channel->next = curr_channel->next;
        } else {
            list = curr_channel->next;
        }
        free(curr_channel);
    }
}

channels_t *find_channel_by_name(channels_t *list, char *name)
{
    if (list == NULL) {
        return NULL;
    }
    channels_t *curr_channel = list;
    while (curr_channel != NULL) {
        if (strcmp(curr_channel->name, name) == 0) {
            return curr_channel;
        }
        curr_channel = curr_channel->next;
    }
    return NULL;
}

channels_t *find_channel_by_uuid(channels_t *list, char *uuid_str)
{
    uuid_t uuid;
    uuid_parse(uuid_str, uuid);

    if (list == NULL) {
        return NULL;
    }
    channels_t *curr_channel = list;
    while (curr_channel != NULL) {
        if (memcmp(curr_channel->uuid, uuid, sizeof(uuid_t)) == 0) {
            return curr_channel;
        }
        curr_channel = curr_channel->next;
    }
    return NULL;
}
