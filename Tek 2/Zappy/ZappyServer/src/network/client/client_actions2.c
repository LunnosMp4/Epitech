/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** client_actions2
*/

#include "server.h"

void ai_or_gui(server_t *s, clients_t **client, char **n, int fd)
{
    if (strcmp(*n, "GRAPHIC\n") == 0 || strcmp(*n, "GRAPHIC") == 0
    || strcmp(*n, "GRAPHIC\r\n") == 0) {
        (*client)->status = GUI;
        s->gui_fd = (*client)->sockfd;
    } else {
        if (is_good_name_team(s->nameX, (*n)) == -1) {
            free(client);
            close(fd);
            (*client) = NULL;
        }
        int place = is_good_name_team(s->nameX, (*n));
        if (place == -1) {
            free(client);
            close(fd);
            (*client) = NULL;
        }
        s->players_in_teams[place]++;
        (*client)->number = s->next_number;
        s->next_number++;
        (*client)->status = AI;
    }
}

void ai_or_gui_actions(server_t **s, clients_t **current, char *name_buffer)
{
    if ((*current) == NULL) {
        return;
    }
    if ((*current)->status == GUI) {
        send_to_gui((*s), (*current));
    } else {
        (*current)->name_team = strdup(name_buffer);
        dprintf((*current)->sockfd, "%d\n", (*s)->clientsNb);
        random_pos(s, current);
        dprintf((*current)->sockfd, "%d %d\n", (*s)->width, (*s)->height);
        gui_commands[5]((*s), (*current));
    }
}
