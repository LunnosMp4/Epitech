/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** init_game.c
*/

#include "my_defender.h"

static void init_sounds(game_t *game)
{
    game->sounds = malloc(sizeof(sounds_t));
    game->sounds->music = malloc(sizeof(sfMusic *) * NB_MUSIC);
    game->sounds->music[0] = sfMusic_createFromFile("assets/sounds/click.wav");
    game->sounds->music[1] =
    sfMusic_createFromFile("assets/sounds/Ashes_on_The_Fire.ogg");
    game->sounds->music[2] =
    sfMusic_createFromFile("assets/sounds/place_turret.wav");
    game->sounds->music[3] =
    sfMusic_createFromFile("assets/sounds/wrong_place_turret.wav");
    sfMusic_play(game->sounds->music[1]);
    sfMusic_setLoop(game->sounds->music[1], sfTrue);
}

static void set_text(sfText *text, sfVector2f pos, int size, sfVector2f scale)
{
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setScale(text, scale);
}

static text_t *init_text(void)
{
    text_t *text = malloc(sizeof(text_t));

    text->level = sfText_create();
    text->popup = sfText_create();
    text->paused = sfText_create();
    set_text(text->level, (sfVector2f) {370, 180},
    60, (sfVector2f) {1.7, 1.7});
    set_text(text->popup, (sfVector2f) {180, 160},
    20, (sfVector2f) {1.7, 1.7});
    set_text(text->paused, (sfVector2f) {320, 200},
    100, (sfVector2f) {1.7, 1.7});
    text->font = sfFont_createFromFile("assets/font.ttf");
    sfText_setFont(text->level, text->font);
    sfText_setFont(text->popup, text->font);
    sfText_setFont(text->paused, text->font);
    sfText_setString(text->level, "Level 1, Biome 1");
    sfText_setString(text->paused, "Pause");
    return text;
}

static config_t *init_config(void)
{
    config_t *conf = malloc(sizeof(config_t));

    conf->next = 1;
    conf->set_map = 1;
    conf->set_biome = 1;
    conf->wave = 4.2;
    conf->difficulty = 1.5;
    conf->steps = 0;
    conf->map = malloc(sizeof(int *) * (MAPY + 1));
    conf->pos_steps = malloc(sizeof(sfVector2f) * (MAPX * MAPY));
    conf->direction = malloc(sizeof(sfVector2f) * (MAPX * MAPY));
    conf->direction[0] = (sfVector2f) {1, 0};
    return conf;
}

game_t *init_game(sfVideoMode mode, sfColor clear_color)
{
    game_t *game = malloc(sizeof(game_t));

    init_sounds(game);
    game->window = sfRenderWindow_create(mode, "My Defender", sfClose, NULL);
    game->text = init_text();
    game->conf = init_config();
    game->state = MENU;
    game->clear_color = clear_color;
    game->clock = sfClock_create();
    game->grab = 0;
    game->pause = 0;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    return game;
}
