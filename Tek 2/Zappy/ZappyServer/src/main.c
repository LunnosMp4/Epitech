/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** main.c
*/

#include "server.h"

static int help_usage(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2");
    printf (" ... -c clientsNB -f freq\n");
    printf("\tport\t   is the port number\n");
    printf ("\twidth\t   is the width of the world\n");
    printf ("\theight\t   is the height of the world\n");
    printf ("\tnameX\t   is the name of the team X\n");
    printf ("\tclientsNB  is the number of authorized clients per team\n");
    printf ("\tfreq\t   is the reciprocal of time unit");
    printf (" for execution of actions\n");
    return 0;
}

bool n_is_in(char **av, int ac)
{
    for (int i = 0; i != ac; i++) {
        if (strcmp(av[i], "-n") == 0)
            return true;
    }
    return false;
}

int main(int ac, char **av)
{
    if (ac == 2 && !strcmp(av[1], "-help")) {
        return help_usage();
    } else if (ac >= 3 && n_is_in(av, ac))
        return if_can_run_serv(av, ac);
    return 84;
}
