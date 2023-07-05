/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** teams_management
*/

#include "server.h"

int *init_teams(int max_players)
{
    int i = 0;
    int *teams = malloc(sizeof(int) * max_players);

    for (; i != max_players; i++) {
        teams[i] = 0;
    }

    return teams;
}

int is_good_name_team(char **name_list, char *name)
{
    for (int i = 0; name_list[i] != NULL; i++) {
        if (strcmp(name_list[i], remove_back_n(name)) == 0) {
            return i;
        }
    }
    return -1;
}
