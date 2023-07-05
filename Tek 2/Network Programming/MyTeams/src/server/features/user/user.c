/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** user.c
*/

#include "server.h"

/* TODO: check if user exists (args[0]) in the linked list
of users if so return uuid and username */

void user(PARAMS_FEATS)
{
    if (s->client->is_logged == false) {
        dprintf(FD, "300 BWA Unauthorized\r\n");
        return;
    }
    if (s->client->request->nb_args != 1) {
        dprintf(FD, "200 BWA Bad request\r\n");
        return;
    }
    for (; s->client; s->client = s->client->next) {
        char uuid_str_search[37];
        uuid_unparse(s->client->uuid, uuid_str_search);

        if (strcmp(uuid_str_search, s->client->request->args[0]) == 0) {
            dprintf(FD, "109 BWA User Result BWA \"%s\" \"%s\" %d\r\n",
            uuid_str_search, s->client->username, s->client->is_logged);
            return;
        }
    }
    dprintf(FD, "209 BWA User not found\r\n");
}
