/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** init_binary.c
*/

#include "my_rpg.h"

void init_map_binary(game_t *game)
{
    if (game->is_on_map == UKR)
        game->map_cols = split_string(read_file
        ("assets/img/map/txt/map_base_col.txt"), '\n');
    if (game->is_on_map == FRONT)
        game->map_cols = split_string(read_file
        ("assets/img/map/txt/map2_warzone_col.txt"), '\n');
    if (game->is_on_map == RUS)
        game->map_cols = split_string(read_file
        ("assets/img/map/txt/enemy_base_col.txt"), '\n');
    if (game->is_on_map == BOSS)
        game->map_cols = split_string(read_file
        ("assets/img/map/txt/inside_enemy_base.txt"), '\n');
}
