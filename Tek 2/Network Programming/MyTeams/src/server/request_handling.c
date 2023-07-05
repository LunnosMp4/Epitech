/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** request.c
*/

#include "server.h"

static const command_handler commands[NB_CMDS] = {
    &login,
    &logout,
    &messages,
    &send_message,
    &subscribe,
    &unsubscribe,
    &subscribed,
    &use,
    &user,
    &users,
    &create,
    &info,
    &list,
    &help
};

static void clear_request(request_t *request)
{
    request->code = 0;
    request->nb_args = 0;
    request->args = NULL;
}

static void parse_request(server_t *s, char *response)
{
    char code[2] = {0};
    char *args = NULL;

    clear_request(s->client->request);
    strncpy(code, response, 2);
    s->client->request->code = atoi(code);
    response += 7;
    args = strtok(response, "\n");
    if (args)
        s->client->request->args = split_args(args, ' ');
    if (s->client->request->args != NULL)
        for (int i = 0; s->client->request->args[i] != NULL; i++)
            s->client->request->nb_args++;
}

static bool check_request(server_t *s, char *buffer)
{
    if (buffer[0] == '\0' || s->client->request->code < 1 ||
        s->client->request->code > NB_CMDS) {
        dprintf(FD, "200 BWA Unknown command\r\n");
        return false;
    }
    return true;
}

void wait_request(char *buffer, server_t *s)
{
    if (read(s->client->sockfd, buffer, BUFSIZ) < 0) {
        printf("read() failed\n");
        return;
    }
    parse_request(s, buffer);
    if (check_request(s, buffer) == false)
        return;
    commands[s->client->request->code - 1](s);
    memset(buffer, '\0', BUFSIZ);
}
