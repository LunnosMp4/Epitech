/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** graphic.c
*/

#include "graphic.h"

int graphic(corewar_t *corewar)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    game_t *game = create_game(mode, sfBlack);
    type_t *type = create_type();

    init_objects(type, corewar);
    process_graphic(game, type);
    process_list(game, type, &type->buttons, destroy_objects);
    free(type);
    destroy_game(game);
    return 0;
}
