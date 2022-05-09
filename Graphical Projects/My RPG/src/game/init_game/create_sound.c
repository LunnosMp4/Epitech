/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** game.c
*/

#include "my_rpg.h"

void volume(game_t *game)
{
    for (int i = 1; i < NB_MUSIC; i++) {
        sfMusic_setVolume(game->music[i], 70);
        sfMusic_setLoop(game->music[MFIGHT], sfTrue);
    }
}

static void config_sounds(game_t *game)
{
    sfSound_setBuffer(game->sounds[RELOAD],
    sfSoundBuffer_createFromFile("assets/sounds/Reload.ogg"));
    sfSound_setBuffer(game->sounds[SHOOT],
    sfSoundBuffer_createFromFile("assets/sounds/Shoot.ogg"));
    sfSound_setBuffer(game->sounds[CLICK],
    sfSoundBuffer_createFromFile("assets/sounds/Click.wav"));
    sfSound_setBuffer(game->sounds[BOMB],
    sfSoundBuffer_createFromFile("assets/sounds/Bomb.wav"));
    sfSound_setBuffer(game->sounds[PLANE],
    sfSoundBuffer_createFromFile("assets/sounds/Plane.wav"));
    sfSound_setBuffer(game->sounds[ROAR],
    sfSoundBuffer_createFromFile("assets/sounds/TransfoBoss.wav"));
    sfSound_setVolume(game->sounds[RELOAD], 40);
    sfSound_setVolume(game->sounds[BOMB], 40);
}

void create_sounds(game_t *game)
{
    game->music = malloc(sizeof(sfMusic *) * NB_MUSIC);
    game->music[MMENU] = sfMusic_createFromFile("assets/sounds/Menu.ogg");
    game->music[MBASE] = sfMusic_createFromFile("assets/sounds/BaseUkr.ogg");
    game->music[MFIGHT] = sfMusic_createFromFile("assets/sounds/Fight.ogg");
    game->music[MBOSS] = sfMusic_createFromFile("assets/sounds/Boss.ogg");
    sfMusic_play(game->music[0]);
    volume(game);
    sfMusic_setVolume(game->music[MBOSS], 120);
    game->sounds = malloc(sizeof(game->sounds) * NB_SOUND);
    game->sounds[RELOAD] = sfSound_create();
    game->sounds[SHOOT] = sfSound_create();
    game->sounds[CLICK] = sfSound_create();
    game->sounds[BOMB] = sfSound_create();
    game->sounds[PLANE] = sfSound_create();
    game->sounds[ROAR] = sfSound_create();
    config_sounds(game);
}
