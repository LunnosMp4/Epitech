/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** manage_team.c
*/

#include "server.h"

teams_t *add_team(teams_t *list, char *name,
char *description, uuid_t uuid)
{
    teams_t *new_team = malloc(sizeof(teams_t));
    new_team->name = name;
    new_team->description = description;
    memcpy(new_team->uuid, uuid, sizeof(uuid_t));
    new_team->next = list;
    list = new_team;
    return new_team;
}

void remove_team(teams_t *list, teams_t *team)
{
    teams_t *prev_team = NULL;
    teams_t *curr_team = list;
    while (curr_team != NULL && curr_team != team) {
        prev_team = curr_team;
        curr_team = curr_team->next;
    }
    if (curr_team == team) {
        if (prev_team != NULL) {
            prev_team->next = curr_team->next;
        } else {
            list = curr_team->next;
        }
        free(curr_team);
    }
}

teams_t *find_team_by_name(teams_t *list, char *name)
{
    if (list == NULL) {
        return NULL;
    }
    teams_t *curr_team = list;
    while (curr_team != NULL) {
        if (strcmp(curr_team->name, name) == 0) {
            return curr_team;
        }
        curr_team = curr_team->next;
    }
    return NULL;
}

teams_t *find_team_by_uuid(teams_t *list, char *uuid_str)
{
    uuid_t uuid;
    uuid_parse(uuid_str, uuid);

    if (list == NULL) {
        return NULL;
    }
    teams_t *curr_team = list;
    while (curr_team != NULL) {
        if (memcmp(curr_team->uuid, uuid, sizeof(uuid_t)) == 0) {
            return curr_team;
        }
        curr_team = curr_team->next;
    }

    return NULL;
}
