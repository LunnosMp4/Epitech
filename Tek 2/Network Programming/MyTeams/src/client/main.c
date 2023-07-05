/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** main.c
*/

#include "client.h"

static void help_usage(void)
{
    printf("USAGE: ./myteams_cli ip port\n\tip");
    printf("\tis the server ip address on which the server socket listens\n");
    printf("\tport\tis the port number on which the server socket listens\n");
    exit(0);
}

client_t *init_client(void)
{
    client_t *client = malloc(sizeof(client_t));

    client->fd = 0;
    client->ip = NULL;
    client->port = 0;
    client->serv_addr.sin_family = 0;
    client->serv_addr.sin_port = 0;
    client->serv_addr.sin_addr.s_addr = 0;
    client->response = malloc(sizeof(response_t));
    client->response->code = 0;
    client->response->message = NULL;
    client->response->args = NULL;
    client->username = NULL;
    uuid_clear(client->uuid);
    return client;
}

int main(int ac, char **av)
{
    client_t *client = init_client();

    if (ac == 2 && !strcmp(av[1], "-help"))
        help_usage();
    check_args(ac, av);
    client->ip = av[IP_ADDRESS];
    client->port = atoi(av[PORT]);
    connection(client);
    return 0;
}
