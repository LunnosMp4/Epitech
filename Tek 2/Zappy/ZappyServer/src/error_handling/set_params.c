/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** set_params
*/

#include "server.h"

void set_xy_params(char **args, int nb, int *w, int *h)
{
    for (int i = 1; i != nb; i++) {
        if (strcmp(args[i], "-x") == 0) {
            *w = atoi(args[i + 1]);
            i++;
        }
        if (strcmp(args[i], "-y") == 0) {
            *h = atoi(args[i + 1]);
            i++;
        }
    }
}

int set_pcf_params(char **args, int nb, int *port, int *clientNb)
{
    int freq = 100;

    for (int i = 1; i != nb; i++) {
        if (strcmp(args[i], "-p") == 0) {
            *port = atoi(args[i + 1]);
            i++;
        }
        if (strcmp(args[i], "-c") == 0) {
            *clientNb = atoi(args[i + 1]);
            i++;
        }
        if (strcmp(args[i], "-f") == 0) {
            freq = atoi(args[i + 1]);
            i++;
        }
    }
    return freq;
}
