/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** client_inventory
*/

#include "server.h"

void init_inventory(inventory_t **inv)
{
    *inv = malloc(sizeof(inventory_t));
    (*inv)->deraumere = 0;
    (*inv)->food = 1;
    (*inv)->linemate = 0;
    (*inv)->mendiane = 0;
    (*inv)->phiras = 0;
    (*inv)->sibur = 0;
    (*inv)->thystame = 0;
}
