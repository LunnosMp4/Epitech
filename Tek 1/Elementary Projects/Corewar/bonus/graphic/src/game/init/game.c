/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** game.c
*/

#include "graphic.h"

void create_sounds(game_t *game)
{
    game->sounds = malloc(sizeof(game->sounds) * NB_SOUND);
    for (int i = 0; i < NB_SOUND; i++)
        game->sounds[i] = sfSound_create();
    sfSound_setBuffer(game->sounds[SPRESSED],
    sfSoundBuffer_createFromFile("Assets/Sounds/OnClick.ogg"));
    sfSound_setBuffer(game->sounds[SPLAY],
    sfSoundBuffer_createFromFile("Assets/Sounds/Lancement.ogg"));
    sfSound_setBuffer(game->sounds[SSTOP],
    sfSoundBuffer_createFromFile("Assets/Sounds/Arrêt.ogg"));
    sfSound_setBuffer(game->sounds[SINFO],
    sfSoundBuffer_createFromFile("Assets/Sounds/Info.ogg"));
    sfSound_setBuffer(game->sounds[SQUIT],
    sfSoundBuffer_createFromFile("Assets/Sounds/Quitter.ogg"));
    sfSound_setVolume(game->sounds[SPRESSED], 70);
    for (int i = 1; i < NB_SOUND; i++)
        sfSound_setVolume(game->sounds[i], 200);
}

game_t *create_game(sfVideoMode mode, sfColor clear_color)
{
    game_t *game = malloc(sizeof(game_t));

    create_sounds(game);
    game->window = sfRenderWindow_create(mode, "Corewar",
    sfResize | sfClose, NULL);
    game->clear_color = clear_color;
    game->btn = false;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    return game;
}
