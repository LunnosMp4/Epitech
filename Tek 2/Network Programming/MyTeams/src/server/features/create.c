/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** create.c
*/

#include "server.h"

void create(PARAMS_FEATS)
{
    if (s->client->is_logged == false) {
        dprintf(FD, "300 BWA Unauthorized\r\n");
        return;
    }

    switch (s->client->request->context) {
        case CTX_NULL: create_team(s);
            break;
        case CTX_TEAM: create_channel(s);
            break;
        case CTX_TEAM_CHANNEL: create_thread(s);
            break;
        case CTX_TEAM_CHANNEL_THREAD: create_reply(s);
            break;
        default: break;
    }
}
