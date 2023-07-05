/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** info_team.c
*/

#include "server.h"

void info_team(PARAMS_FEATS)
{
    teams_t *team = find_team_by_uuid(s->teams, s->client->request->uuid_team);
    dprintf(FD, "112 BWA Team info BWA \"%s\" \"%s\" \"%s\"\r\n",
    s->client->request->uuid_team, team->name, team->description);
}
