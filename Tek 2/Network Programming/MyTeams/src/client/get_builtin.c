/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** get_builtin.c
*/

#include "client.h"

static const builtin_t builtins[NB_CMDS] = {
    {"/create", &create_cmd},
    {"/help", &help_cmd},
    {"/info", &info_cmd},
    {"/list", &list_cmd},
    {"/login", &login_cmd},
    {"/logout", &logout_cmd},
    {"/messages", &messages_cmd},
    {"/send", &send_cmd},
    {"/subscribe", &subscribe_cmd},
    {"/subscribed", &subscribed_cmd},
    {"/unsubscribe", &unsubscribe_cmd},
    {"/use", &use_cmd},
    {"/user", &user_cmd},
    {"/users", &users_cmd},
};

builtin_t *get_builtin(char *buffer)
{
    char *cmd = NULL;

    if (!buffer || buffer[0] == '\n')
        return NULL;
    if (strchr(buffer, ' '))
        cmd = strtok(strdup(buffer), " ");
    else
        cmd = strtok(strdup(buffer), "\n");
    for (int i = 0; i < NB_CMDS; i++) {
        if (!strcmp(cmd, builtins[i].cmd)) {
            free(cmd);
            return ((builtin_t *)&builtins[i]);
        }
    }
    free(cmd);
    printf("Error: Command not found\n");
    return NULL;
}
