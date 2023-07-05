/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** parse_response.c
*/

#include "client.h"

static void clear_response(response_t *response)
{
    response->code = 0;
    response->message = NULL;
    response->args = NULL;
}

static bool parse_response(client_t *client, char *response)
{
    char code[3] = {0};
    char *args = NULL;

    clear_response(client->response);
    strncpy(code, response, 3);
    client->response->code = atoi(code);
    response += 8;
    if (strstr(response, " BWA ")) {
        args = strdup(strstr(response, " BWA ")) + 5;
        args = strtok(args, "\r\n");
        int len_msg = count_until(response, " BWA ");
        client->response->message = malloc(sizeof(char) * (len_msg + 1));
        strncpy(client->response->message, response, len_msg);
        client->response->message[len_msg] = '\0';
    } else
        client->response->message = strtok(response, "\r\n");
    if (args)
        client->response->args = split_args(args, ' ');
    return true;
}

int wait_response(client_t *client)
{
    char response[MAX_BUFFER_SIZE] = {0};

    while (read(client->fd, response, MAX_BUFFER_SIZE) > 0) {
        if (parse_response(client, response) == true)
            break;
        memset(response, 0, MAX_BUFFER_SIZE);
    }
    printf("%d: %s\n", client->response->code, client->response->message);
    if (client->response->code == 200)
        return ERROR;
    if (client->response->code == 300)
        return UNAUTHORIZED;
    return OK;
}
