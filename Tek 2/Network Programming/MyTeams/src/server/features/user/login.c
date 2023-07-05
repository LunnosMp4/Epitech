/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** login.c
*/

#include "server.h"

void login(PARAMS_FEATS)
{
    char uuid_str[37];

    if (s->client->request->args == NULL || s->client->request->nb_args != 1
        || s->client->is_logged == true) {
        dprintf(FD, "200 BWA Bad request\r\n");
        return;
    }
    s->client->username = strdup(s->client->request->args[0]);
    uuid_generate(s->client->uuid);
    uuid_unparse(s->client->uuid, uuid_str);
    server_event_user_logged_in(uuid_str);
    s->client->is_logged = true;
    dprintf(FD, "101 BWA Login successful BWA \"%s\" \"%s\"\r\n",
    uuid_str, s->client->username);
    return;
}
