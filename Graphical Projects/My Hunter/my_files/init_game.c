/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-loic.tisseyre
** File description:
** init_game.c
*/

#include "../include/my_structures.h"

void init_texture(game_t *game, entity_t *entity, animation_t *animation)
{
    sfVector2f origin = {0, 50};
    sfSprite_setPosition(entity->sprite, origin);
    sfSprite_setTextureRect(entity->sprite, animation->rect);
    sfSprite_setTextureRect(entity->blood, animation->rect2);
    sfSprite_setTexture(entity->cursor, entity->texcursor, sfTrue);
    sfSprite_setTexture(entity->blood, entity->bloodtex, sfTrue);
    sfSprite_setTexture(entity->sprite_background, \
    entity->background, sfTrue);
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
}

void init_text2(game_t *game)
{
    sfVector2f textpos4 = {500, 440};
    sfVector2f textpos5 = {165, 220};
    sfVector2f scale = {1.5, 1.5};
    sfVector2f scale2 = {2, 2};
    game->textL = sfText_create();
    sfText_setFont(game->textL, game->font);
    sfText_setScale(game->textL, scale);
    sfText_setPosition(game->textL, textpos4);
    sfText_setColor(game->textL, sfRed);
    game->textGO = sfText_create();
    sfText_setFont(game->textGO, game->font);
    sfText_setScale(game->textGO, scale2);
    sfText_setPosition(game->textGO, textpos5);
    sfText_setColor(game->textGO, sfRed);
}

void init_text(game_t *game)
{
    sfVector2f textpos = {500, 20};
    sfVector2f textpos2 = {750, 440};
    sfVector2f textpos3 = {220, 20};
    sfVector2f scale = {1.5, 1.5};
    game->text = sfText_create();
    game->font = sfFont_createFromFile("images/my_font.TTF");
    sfText_setFont(game->text, game->font);
    sfText_setPosition(game->text, textpos);
    sfText_setScale(game->text, scale);
    game->textLoose = sfText_create();
    sfText_setFont(game->textLoose, game->font);
    sfText_setPosition(game->textLoose, textpos2);
    sfText_setScale(game->textLoose, scale);
    sfText_setColor(game->textLoose, sfRed);
    game->textS = sfText_create();
    sfText_setFont(game->textS, game->font);
    sfText_setScale(game->textS, scale);
    sfText_setPosition(game->textS, textpos3);
    init_text2(game);
}

void init_game(game_t *game, entity_t *entity, animation_t *animation)
{
    game->speed = 10;
    entity->background = \
    sfTexture_createFromFile("images/background.png", NULL);
    entity->texture = sfTexture_createFromFile("images/coinccoinc.png", NULL);
    entity->texcursor = sfTexture_createFromFile("images/aim.png", NULL);
    entity->bloodtex = sfTexture_createFromFile("images/blood.png", NULL);
    entity->sprite = sfSprite_create();
    entity->sprite_background = sfSprite_create();
    entity->cursor = sfSprite_create();
    entity->blood = sfSprite_create();
    init_texture(game, entity, animation);
    animation->rect = (sfIntRect) {0, 0, 110, 770};
    animation->rect2 = (sfIntRect) {0, 0, 256, 1536};
    animation->clock = sfClock_create();
    animation->clock2 = sfClock_create();
    game->loose = 3;
    init_text(game);
}
