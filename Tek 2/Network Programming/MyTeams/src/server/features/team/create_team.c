/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** create_team.c
*/

#include "server.h"

static void print_team(server_t *s, char *team_uuid,
char *team_name, char *team_desc)
{
    char user_uuid[37];
    uuid_unparse(s->client->uuid, user_uuid);

    dprintf(FD, "111 BWA Team created BWA \"%s\" \"%s\" \"%s\"\r\n",
        team_uuid, team_name, team_desc);
    server_event_team_created(team_uuid, team_name, user_uuid);
}

static bool check_params(int nb_args, char **args)
{
    if (nb_args != 2)
        return false;
    if (strlen(args[0]) > MAX_NAME_LENGTH)
        return false;
    if (strlen(args[1]) > MAX_DESCRIPTION_LENGTH)
        return false;
    return true;
}

void create_team(PARAMS_FEATS)
{
    if (!check_params(s->client->request->nb_args,
    s->client->request->args)) {
        dprintf(FD, "200 BWA Bad request\r\n");
        return;
    }
    char *team_name = s->client->request->args[0];
    char *team_desc = s->client->request->args[1];
    char team_uuid[37];
    uuid_t uuid;
    if (find_team_by_name(s->teams, team_name) != NULL) {
        dprintf(FD, "211 BWA Team Already Exist\r\n");
        return;
    }
    uuid_generate(uuid);
    uuid_unparse(uuid, team_uuid);
    s->teams = add_team(s->teams, team_name, team_desc, uuid);
    print_team(s, team_uuid, team_name, team_desc);
}
