/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** parse
*/

#include "server.h"

void parse_request(server_t *s, char *response)
{
    char *args = malloc(sizeof(char) * (strlen(response) + 1));

    memset(args, '\0', (strlen(response) + 1));
    s->client->request = (request_t*)malloc(sizeof(request_t));
    clear_request(s->client->request);
    args = remove_back_n(response);
    if (args) {
        s->client->request->args = split_args(args);
    }

    if (s->client->request->args != NULL) {
        for (int i = 1; s->client->request->args[i] != NULL; i++)
            s->client->request->nb_args++;
    }
}
