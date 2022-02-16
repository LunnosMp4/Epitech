/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-loic.tisseyre
** File description:
** run_game.c
*/

#include "../include/my_runner.h"
#include "../include/object.h"

void set_background_animation(game_t *game, object_t *object, fond_t *fond);
void set_fox_run(game_t *game, object_t *object, fond_t *fond);
void logspd(game_t *game, object_t *object, fond_t *fond);
sfBool collision(game_t *game, object_t *object, fond_t *fond);
sfBool collision2(game_t *game, object_t *object, fond_t *fond);
char *convert_int_to_string(int str, char tot[]);
void read_map(char *buffer, fond_t *fond, game_t *game);

void run_game(game_t *game, fond_t *fond, char *buffer)
{
    sfVideoMode mode = {800, 600, 32};
    sfColor clear_color = sfBlack;
    text_init(game);
    init(fond);
    set_movement(game);
    read_map(buffer, fond, game);
    game = create_game(mode, game, clear_color);
}

void run_animations(game_t *game, object_t *object, fond_t *fond)
{
    char string[100];
    game->buff = convert_int_to_string(game->score, string);
    sfText_setString(game->text, game->buff);
    sfText_setString(game->textwin, "Victory !");
    sfText_setString(game->textloose, "Game Over !");
    sfText_setString(game->textpause, "Pause");
    set_fox_run(game, object, fond);
    logspd(game, object, fond);
    set_background_animation(game, object, fond);
}

void change_score(game_t *game, fond_t *fond)
{
    if (game->score > 0 && game->score < 300)
        game->score -= 250;
    else if (game->score > 300 && game->score < 600)
        game->score -= 450;
    else if (game->score > 600 && game->score < 1000)
        game->score -= 800;
}

void detect_collision(game_t *game, object_t *object,
fond_t *fond, sfVector2f origin)
{
    bool colorRed = false ;
    sfVector2f origin2 = {fond->nb2, 450};
    if (collision(game, object, fond) == sfTrue) {
        sfSprite_setPosition(fond->log->sprite, origin);
        change_score(game, fond);
    } else if (collision2(game, object, fond) == sfTrue) {
        sfSprite_setPosition(fond->log2->sprite, origin2);
        change_score(game, fond);
    } else {
        draw_game(game, object, fond);
    }
}