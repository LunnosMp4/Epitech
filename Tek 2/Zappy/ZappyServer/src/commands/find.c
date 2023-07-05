/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** find
*/

#include "server.h"

int find_team(char **list_team, char *team)
{
    int pos = 0;

    for (; strcmp(list_team[pos], team) == 0; pos++);
    return pos;
}
