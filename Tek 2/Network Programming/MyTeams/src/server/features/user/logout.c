/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** logout.c
*/

#include "server.h"

void logout(PARAMS_FEATS)
{
    char uuid_str[37];

    if (s->client->is_logged == false) {
        dprintf(FD, "300 BWA Unauthorized\r\n");
        return;
    }
    if (s->client->request->nb_args != 0) {
        dprintf(FD, "200 BWA Bad request\r\n");
        return;
    }
    uuid_unparse(s->client->uuid, uuid_str);
    dprintf(FD, "102 BWA Logout successful\r\n");
    server_event_user_logged_out(uuid_str);
    s->client->is_logged = false;
}
