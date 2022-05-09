/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** main.c
*/

#include "my_rpg.h"

static void help_h_pt2(void)
{
    my_putstr("\tLEFT\tMove left\n");
    my_putstr("\tRIGHT\tMove right\n");
    my_putstr("\tESCAPE\tPause the game\n");
    my_putstr("\tSPACE\tShoot\n");
    my_putstr("\tR\tReload\n");
    my_putstr("\tA\tInteract / Talk to NPCs / Next dialog\n");
    my_putstr("\tE\tUse Health\n");
}

static int help_h(int ac, char **av)
{
    if (ac == 2 && str_isequal(av[1], "-h", true)) {
        my_putstr("USAGE\n\t./my_rpg\n\nDESCRIPTION\n\t");
        my_putstr("Ukraine RPG is a game where you can play as a ukrainian");
        my_putstr(" soldier.\n\tYour goal is to find Putin and Defeat him.\n");
        my_putstr("INGAME COMMANDS\n");
        my_putstr("\tUP\tMove up\n");
        my_putstr("\tDOWN\tMove down\n");
        help_h_pt2();
        return 1;
    } else if (ac == 2) {
        my_putstr("USAGE\n\tLaunch game\t./my_rpg\n\
        Display Help\t./my_rpg -h\n");
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    srand(time(NULL));
    if (help_h(ac, av) == 1)
        return 0;
    game_t *game = create_game(mode, sfBlack);
    menu_t *menu = create_menu();
    lnk_ltype_t *ltype = create_ltype();

    process_game(game, menu, ltype);
    process_ltype(game, *ltype, &ltype->enemy, destroy_object);
    free(ltype);
    destroy_game(game);
    return 0;
}
