/*
** EPITECH PROJECT, 2021
** Bootstrap MyHunter
** File description:
** myhunter.c
*/

#include "../include/my_structures.h"
#include "../include/my_functions.h"

void my_description(void)
{
    my_putstr("USAGE :\n");
    my_putstr("     ./my_hunter\n\n");
    my_putstr("COMMANDS :\n");
    my_putstr("     Use left clic to shoot, try to shoot the ducks !\n");

}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            my_description();
        }
    } else {
        sfVideoMode mode = {WIDTH, HEIGHT, 32};
        game_t *game = malloc(sizeof(game_t));
        animation_t *animation = malloc(sizeof(animation_t));
        entity_t *entity = malloc(sizeof(entity_t));;
        game->music = sfMusic_createFromFile("sounds/Natural.wav");
        sfMusic_play(game->music);
        sfColor clear_color = sfBlack;
        sfEvent event;

        init_game(game, entity, animation);
        game = create_game(mode, game, clear_color);
        process_game(event, game, entity, animation);
        destroy_game(game, entity, animation);
    }
    return 0;
}