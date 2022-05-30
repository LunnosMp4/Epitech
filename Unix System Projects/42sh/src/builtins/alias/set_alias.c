/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-enzo.daumalle
** File description:
** set_allias.c
*/

#include "my_sh.h"

bool replace_alias(env_t **env, char *cmd, char *line)
{
    for (env_t *tmp = *env; tmp; tmp = tmp->next)
        if (str_isequal(tmp->key, cmd, true)) {
            tmp->value = my_strdup(line);
            return true;
        }
    return false;
}

void set_alias(char *line, env_t **list, UNUSED char **env)
{
    int len_cmd = 0;
    char **cmd = strsplit(line, " \t", false);

    line += find_word(line, cmd[2]);
    for (len_cmd = 0; cmd[len_cmd]; len_cmd += 1);
    if (len_cmd == 1)
        return exec_alias(list);
    if (len_cmd == 2 || replace_alias(list, cmd[1], line)) {
        p_ntty(HEADER, *list);
        return;
    }
    if (len_cmd >= 3 && str_isequal(cmd[1], "alias", true)) {
        fprintf(stderr, "alias: Too dangerous to alias that.\n");
        p_ntty(HEADER, *list);
        return;
    }
    if (len_cmd >= 3)
        add_node_at_back(cmd[1], line, ALIAS, list);
    p_ntty(HEADER, *list);
}
