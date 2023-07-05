/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** create_thread.c
*/

#include "server.h"

static bool check_threads_args(server_t *s)
{
    if (s->client->request->nb_args != 2) {
        dprintf(FD, "200 BWA Bad request\r\n");
        return false;
    }
    if (strlen(s->client->request->args[0]) > MAX_NAME_LENGTH) {
        dprintf(FD, "200 BWA Bad request\r\n");
        return false;
    }
    if (strlen(s->client->request->args[1]) > MAX_BODY_LENGTH) {
        dprintf(FD, "200 BWA Bad request\r\n");
        return false;
    }
    return true;
}

static void print_threads(server_t *s, char **args,
char *thread_uuid_str, char *client_uuid_str)
{
    server_event_thread_created(s->client->request->uuid_channel,
    thread_uuid_str, client_uuid_str, args[0], args[1]);
    dprintf(FD, "111 BWA Thread created BWA \"%s\" \"%s\" \"%s\" %ld\r\n",
    thread_uuid_str, s->threads->title,
    s->threads->message, s->threads->timestamp);
}

void create_thread(PARAMS_FEATS)
{
    if (!check_threads_args(s))
        return;
    char *args[2] = {s->client->request->args[0], s->client->request->args[1]};
    if (find_thread_by_title(s->threads, args[0])) {
        dprintf(FD, "211 BWA Thread Already Exist\r\n");
        return;
    }
    char thread_uuid_str[37];
    char client_uuid_str[37];
    uuid_t thread_uuid;
    uuid_t uuid_list[2];
    uuid_generate(uuid_list[0]);
    memcpy(uuid_list[1], s->client->uuid, sizeof(uuid_t));
    uuid_unparse(thread_uuid, thread_uuid_str);
    uuid_unparse(s->client->uuid, client_uuid_str);
    s->threads = add_thread(s->threads, args, uuid_list,
    find_channel_by_uuid(s->channels, s->client->request->uuid_channel));
    print_threads(s, args, thread_uuid_str, client_uuid_str);
}
