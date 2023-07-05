/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** config_game.h
*/

#ifndef CONFIG_H
    #define CONFIG_H
    #include "my_defender.h"

typedef struct config {
    int next;
    int set_map;
    int set_biome;
    float wave;
    float difficulty;
    int steps;
    int **map;
    sfVector2f *pos_steps;
    sfVector2f *direction;
} config_t;


#endif /* CONFIG_H_ */
