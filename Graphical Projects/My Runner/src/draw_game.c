/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-loic.tisseyre
** File description:
** draw_game.c
*/

#include "../include/my_runner.h"
#include "../include/object.h"

void draw_gameloose(game_t *game, object_t *object, fond_t *fond)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, fond->object1->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object0->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object2->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object3->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object4->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object5->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object7->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object6->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object8->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->textloose, NULL);
    sfRenderWindow_display(game->window);
}

void draw_gamewin(game_t *game, object_t *object, fond_t *fond)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, fond->object1->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object0->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object2->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object3->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object4->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object5->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object7->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object6->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object8->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->textwin, NULL);
    sfRenderWindow_display(game->window);
}

void draw_game2(game_t *game, object_t *object, fond_t *fond)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, fond->object1->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object0->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object2->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object3->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object4->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object5->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object7->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object6->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->start->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->log->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->log2->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->fox->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fond->object8->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    if (game->pause == 1)
        sfRenderWindow_drawText(game->window, game->textpause, NULL);
    sfRenderWindow_display(game->window);
}