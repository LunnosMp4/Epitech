/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-loic.tisseyre
** File description:
** main.c
*/

#include "../include/my_runner.h"
#include "../include/object.h"

int error_handling(int ac, char **av)
{
    if (ac > 4 || ac < 2) {
        my_putstr("Wrong usage, please refer to ./my_runner -h\n");
        return -1;
    }
}

int usage(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("Try to reach 1000 pts !\n\n");
        my_putstr("Usage:\n     ./my_runner maps/map1.txt\n\n");
        my_putstr("FONCTIONS:\n");
        my_putstr("     ./my_runner maps/map2.txt -i (infinite mod)\n");
        my_putstr("     ./my_runner maps/map1.txt 'color' (change \
color character)\n");
        my_putstr("     ./my_runner maps/map2.txt -i 'color' \
(change color character in infinite mod)\n");
        my_putstr("     color :\n         ice\n         fire\n\n");
        my_putstr("KEYBINDS:\n");
        my_putstr("     Use spacebar to jump !\n");
        my_putstr("     Use P to pause the game !\n\n");
        my_putstr("MAPS:\n");
        my_putstr("     If You want to create a map, check the \
.legend file in the maps/ folder.\n");
        return -1;
    }
    return 0;
}

void info_map(char *buffer, fond_t *fond, game_t *game)
{
    for (;buffer[game->n1] != '1'; game->n1++);
    for (;buffer[game->n2] != '2'; game->n2++);
    for (;buffer[game->n3] != '3'; game->n3++);
    if (game->n1 < 50)
        game->spd = -8;
    else if (game->n2 < 50)
        game->spd = -9;
    else if (game->n3 < 50)
        game->spd = -10;
    else
        game->spd = -8;
    my_putstr("log 1 = ");
    my_put_nbr(fond->nb);
    my_putstr("\n");
    my_putstr("log 2 = ");
    my_put_nbr(fond->nb2);
    my_putstr("\n");
}

void read_map(char *buffer, fond_t *fond, game_t *game)
{
    int i = 0;
    int c = 0;
    char str[999999];
    for (;buffer[i] != 'x'; i++);
    for (;buffer[c] != 'o'; c++);
    if (i > 1800)
        i = 10;
    if (c > 1800);
        c = 20;
    int tot = (i * 50) + 800;
    int tot2 = (c * 50) + 800;
    fond->nb = tot;
    fond->nb2 = tot2;
    info_map(buffer, fond, game);
    sfVector2f pos = {fond->nb, 450};
    sfVector2f pos2 = {fond->nb2, 450};
    sfSprite_setPosition(fond->log->sprite, pos);
    sfSprite_setPosition(fond->log2->sprite, pos2);
}

int main(int ac, char **av)
{
    if (error_handling(ac, av) == -1)
        return 84;
    if (usage(ac, av) == -1)
        return 0;
    int fd = open(av[1], O_RDONLY);
    char buffer[999999];
    size_t size = 999999;
    if (fd < 0)
        return 84;
    read(fd, buffer, size);
    object_t *object;
    game_t *game = malloc(sizeof(game_t));
    fond_t *fond = malloc(sizeof(fond_t));
    sfEvent event;
    set_object(object, fond, av, ac);
    run_game(game, fond, buffer);
    process_game(event, game, object, fond);
    destroy_game(game, object, fond);
    return 0;
}
