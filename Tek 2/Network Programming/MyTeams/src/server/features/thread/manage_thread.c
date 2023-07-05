/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** manage_thread.c
*/

#include "server.h"

threads_t *add_thread(threads_t *list, char **args,
uuid_t *uuid_list, channels_t *channel)
{
    threads_t *new_thread = malloc(sizeof(threads_t));
    time_t timestamp;
    time(&timestamp);
    new_thread->timestamp = timestamp;
    new_thread->title = args[0];
    new_thread->message = args[1];
    memcpy(new_thread->uuid, uuid_list[0], sizeof(uuid_t));
    memcpy(new_thread->uuid_author, uuid_list[1], sizeof(uuid_t));
    new_thread->channel = channel;
    new_thread->next = list;
    list = new_thread;
    return new_thread;
}

void remove_thread(threads_t *list, threads_t *thread)
{
    threads_t *prev_thread = NULL;
    threads_t *curr_thread = list;
    while (curr_thread != NULL && curr_thread != thread) {
        prev_thread = curr_thread;
        curr_thread = curr_thread->next;
    }
    if (curr_thread == thread) {
        if (prev_thread != NULL) {
            prev_thread->next = curr_thread->next;
        } else {
            list = curr_thread->next;
        }
        free(curr_thread);
    }
}

threads_t *find_thread_by_title(threads_t *list, char *title)
{
    if (list == NULL) {
        return NULL;
    }
    threads_t *curr_thread = list;
    while (curr_thread != NULL) {
        if (strcmp(curr_thread->title, title) == 0) {
            return curr_thread;
        }
        curr_thread = curr_thread->next;
    }
    return NULL;
}

threads_t *find_thread_by_uuid(threads_t *list, char *uuid_str)
{
    uuid_t uuid;
    uuid_parse(uuid_str, uuid);

    if (list == NULL) {
        return NULL;
    }
    threads_t *curr_thread = list;
    while (curr_thread != NULL) {
        if (memcmp(curr_thread->uuid, uuid, sizeof(uuid_t)) == 0) {
            return curr_thread;
        }
        curr_thread = curr_thread->next;
    }
    return NULL;
}
