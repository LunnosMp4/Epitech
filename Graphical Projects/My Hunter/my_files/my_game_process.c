/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-loic.tisseyre
** File description:
** my_game_process.c
*/

#include "../include/my_structures.h"

char *convert_int_to_string(int i, char b[]);
void init_game(game_t *game, entity_t *entity, animation_t *animation);
void sinusoidal_movement(entity_t *entity , game_t *game);
void blood_explosion(animation_t *animation, game_t *game, entity_t *entity);
void is_dead(game_t *game, entity_t *entity, animation_t *animation);

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

game_t *create_game(sfVideoMode mode, game_t *game, sfColor clear_color)
{
    game->window = sfRenderWindow_create(mode, "My Hunter", sfClose, NULL);
    sfWindow_setFramerateLimit(game->window, 60);
    game->clear_color = clear_color;
    return game;
}

void draw_game(game_t *game, entity_t *entity, animation_t *animation)
{
    if (game->loose <= 0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfMusic_stop(game->music);
        sfMusic_stop(game->gun);
        sfMusic_stop(game->blood);
        sfRenderWindow_drawText(game->window, game->textGO, NULL);
    } else {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, \
        entity->sprite_background, NULL);
        is_dead(game, entity, animation);
        sinusoidal_movement(entity, game);
        sfRenderWindow_drawText(game->window, game->textS, NULL);
        sfRenderWindow_drawText(game->window, game->textL, NULL);
        sfRenderWindow_drawText(game->window, game->text, NULL);
        sfRenderWindow_drawText(game->window, game->textLoose, NULL);
        sfRenderWindow_drawSprite(game->window, entity->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, entity->cursor, NULL);
    }
    sfRenderWindow_display(game->window);
}

void process_game(sfEvent event, game_t *game, \
entity_t *entity, animation_t *animation)
{
    sfVector2f out = {0, 0};
    char string[100];
    char string2[100];
    sfSprite_setPosition(entity->blood, out);
    while (sfRenderWindow_isOpen(game->window)) {
        game->buff = convert_int_to_string(game->score, string);
        game->buff2 = convert_int_to_string(game->loose, string2);
        sfText_setString(game->textS, "Score :");
        sfText_setString(game->textL, "Lives :");
        sfText_setString(game->textGO, "Game Over");
        sfText_setString(game->text, game->buff);
        sfText_setString(game->textLoose, game->buff2);
        sfVector2f movex = {game->speed, 0};
        my_crosshair(game, entity);
        blood_explosion(animation, game, entity);
        run_animation(animation, game, entity, movex);
        set_spawn(game->window, entity, game);
        while (sfRenderWindow_pollEvent(game->window, &event)) {
            analyse_events(game, event, entity, animation);
        }
        draw_game(game, entity, animation);
    }
}

void destroy_game(game_t *game, entity_t *entity, animation_t *animation)
{
    sfMusic_destroy(game->music);
    sfMusic_destroy(game->blood);
    sfMusic_destroy(game->gun);
    sfSprite_destroy(entity->sprite);
    sfSprite_destroy(entity->sprite_background);
    sfTexture_destroy(entity->texture);
    sfTexture_destroy(entity->background);
    sfRenderWindow_destroy(game->window);
    free(entity);
    free(game);
    free(animation);
}