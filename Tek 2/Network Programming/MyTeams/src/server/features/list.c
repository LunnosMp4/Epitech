/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** list.c
*/

#include "server.h"

void list(PARAMS_FEATS_UNUSED)
{
    if (s->client->is_logged == false) {
        dprintf(FD, "300 BWA Unauthorized\r\n");
        return;
    }

    switch (s->client->request->context) {
        case CTX_NULL: list_team(s);
            break;
        case CTX_TEAM: list_channel(s);
            break;
        case CTX_TEAM_CHANNEL: list_thread(s);
            break;
        case CTX_TEAM_CHANNEL_THREAD: list_reply(s);
            break;
        default: break;
    }
}
