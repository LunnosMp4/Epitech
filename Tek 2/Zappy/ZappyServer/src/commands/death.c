/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** death
*/

#include "server.h"

static void is_dead(server_t *s, clients_t *curr, clients_t **client,
struct timeval current_time)
{
    if (curr->inv->food == 0) {
        shutdown(curr->sockfd, SHUT_RDWR);
        close(curr->sockfd);
        int index = find_team(s->nameX, curr->name_team);
        s->players_in_teams[index]--;
        delete_client(client, curr->sockfd);
    } else {
        curr->inv->food--;
        gettimeofday(&current_time, NULL);
        curr->born_timer = current_time;
    }
}

void check_death_players(server_t *s, clients_t **client, int timer)
{
    clients_t *curr = *client;
    struct timeval current_time;
    double elapsed_seconds;
    double needed_time = 126 / timer;

    if (!(*client))
        return;

    while (curr != NULL) {
        clients_t *next = curr->next;
        if (curr->status != GUI) {
            gettimeofday(&current_time, NULL);
            elapsed_seconds = current_time.tv_sec - curr->born_timer.tv_sec;
        }
        if (curr->status != GUI && elapsed_seconds >= needed_time) {
            is_dead(s, curr, client, current_time);
        }
        curr = next;
    }
}
