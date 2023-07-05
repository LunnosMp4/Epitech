/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** check_args.c
*/

#include "server.h"

static int find_n(char **args)
{
    int i = 0;

    for (; args[i] != NULL; i++) {
        if (strcmp("-n", args[i]) == 0)
            break;
    }

    return i + 1;
}

char **setup_teams_name(char **current, int n_pos, int *max, int ac)
{
    int j = 0;
    char **new_args = NULL;
    int temp = 0;
    for (int h = n_pos; current[h] != NULL; h++, temp++);
    new_args = malloc(sizeof(char *) * (temp + 1));
    for (int i = n_pos; i != ac; i++, j++) {
        if (strcmp(current[i], "-p") == 0 || strcmp(current[i], "-x") == 0 ||
        strcmp(current[i], "-y") == 0 || strcmp(current[i], "-c") == 0 ||
        strcmp(current[i], "-f") == 0 || strcmp(current[i], "-f") == 0)
            break;
        new_args[j] = strdup(current[i]);
    }
    new_args[j] = NULL;
    *max = temp;
    return new_args;
}

char **check_args(char **args, int nb, int port, int width)
{
    int height = 10;
    int clientNb = 1;
    int freq = 100;
    int max = 0;
    int i = 5;
    char **new_args = setup_teams_name(args, find_n(args), &max, nb);
    freq = set_pcf_params(args, nb, &port, &clientNb);
    set_xy_params(args, nb, &width, &height);
    check_all(port, width, height, clientNb);
    check_freq(freq);
    char **new_new_args = malloc(sizeof(char *) * ((5 + max) + 1));
    new_new_args[0] = strdup(to_string(port));
    new_new_args[1] = strdup(to_string(width));
    new_new_args[2] = strdup(to_string(height));
    new_new_args[3] = strdup(to_string(clientNb));
    new_new_args[4] = strdup(to_string(freq));
    for (int k = 0; new_args[k] != NULL; i++, k++)
        new_new_args[i] = strdup(new_args[k]);
    new_new_args[i] = NULL;
    return free_new_args(new_args, new_new_args);
}
