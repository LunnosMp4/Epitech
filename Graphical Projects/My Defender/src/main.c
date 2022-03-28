/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** main.c
*/

#include "my_defender.h"

static int display_h(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("Usage :\n");
        my_putstr("    ./my_defender\n");
        my_putstr("Key :\n");
        my_putstr("    Escape - Go back to menu or quit \
the game if you're in menu.\n");
        my_putstr("    P - Paused The game (press P to resume).\n");
        my_putstr("    Left Click - On Turret Menu, select a Turret.\n");
        my_putstr("    Right Click - Place a Turret.\n");
        my_putstr("\nEnjoy The Game !!!\n");
        return -1;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (display_h(ac, av) == -1)
        return 0;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    lnk_ltype_t *ltype = init_lnk_ltype();
    game_t *game = init_game(mode, sfBlack);
    menu_t *menu = init_menu(game);

    init_bar_buttons(ltype);
    process_game(game, ltype, menu);
    process_list(ltype->mobs, game, destroy_object);
    free(ltype);
    destroy_game(game);
    return 0;
}
