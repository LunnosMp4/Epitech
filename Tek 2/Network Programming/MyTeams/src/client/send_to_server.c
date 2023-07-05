/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** prototype_cmd.c
*/

#include "client.h"

void send_to_server(char *command_name, char *buffer,
char *command_code, client_t *client)
{
    int len_cmd = strlen(command_name);
    int len_cmd_code = strlen(command_code);
    char protocol_str[strlen(buffer) + len_cmd_code];

    strcpy(protocol_str, command_code);
    strcat(protocol_str, buffer + len_cmd);
    send(client->fd, protocol_str, strlen(protocol_str), 0);
}
