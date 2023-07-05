/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** info_thread.c
*/

#include "server.h"

void info_thread(PARAMS_FEATS)
{
    threads_t *threads = find_thread_by_uuid(s->threads,
    s->client->request->uuid_thread);
    char uuid_author[37];
    uuid_unparse(threads->uuid_author, uuid_author);
    dprintf(FD, "112 BWA Thread info BWA \"%s\" \"%s\" %ld \"%s\" \"%s\" \r\n",
    s->client->request->uuid_thread, uuid_author, threads->timestamp,
    threads->title, threads->message);
}
