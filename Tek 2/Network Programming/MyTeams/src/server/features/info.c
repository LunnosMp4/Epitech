/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** info.c
*/

#include "server.h"

void info(PARAMS_FEATS_UNUSED)
{
    if (s->client->is_logged == false) {
        dprintf(FD, "300 BWA Unauthorized\r\n");
        return;
    }

    switch (s->client->request->context) {
        case CTX_NULL: info_user(s);
            break;
        case CTX_TEAM: info_team(s);
            break;
        case CTX_TEAM_CHANNEL: info_channel(s);
            break;
        case CTX_TEAM_CHANNEL_THREAD: info_thread(s);
            break;
        default: break;
    }
}
