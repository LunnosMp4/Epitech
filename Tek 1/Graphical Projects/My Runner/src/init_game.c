/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-loic.tisseyre
** File description:
** init_game.c
*/

#include "../include/my_runner.h"
#include "../include/object.h"

void init(fond_t *fond)
{
    fond->clock = sfClock_create();
    fond->clock2 = sfClock_create();
    fond->rect = (sfIntRect) {0, 0, 800, 600};
    fond->rect1 = (sfIntRect) {0, 0, 800, 600};
    fond->rect2 = (sfIntRect) {0, 0, 800, 600};
    fond->rect3 = (sfIntRect) {0, 0, 800, 600};
    fond->rect4 = (sfIntRect) {0, 0, 800, 600};
    fond->rect5 = (sfIntRect) {0, 0, 800, 600};
    fond->rect6 = (sfIntRect) {0, 0, 800, 600};
    fond->rect7 = (sfIntRect) {0, 0, 800, 600};
    fond->rectfox = (sfIntRect) {0, 0, 468, 468};
    fond->rect8 = (sfIntRect) {0, 0, 800, 600};
    fond->rectlog = (sfIntRect) {0, 0, 230, 193};
    fond->MainMusic = sfMusic_createFromFile("song/my_game_song.ogg");
}

void text_init(game_t *game)
{
    sfVector2f textpos = {360, 50};
    sfVector2f textpos2 = {280, 250};
    sfVector2f textpos3 = {320, 250};
    sfVector2f textpos4 = {70, 250};
    sfVector2f scale = {1.2, 1.2};
    game->font = sfFont_createFromFile("images/my_font.TTF");
    game->text = sfText_create();
    sfText_setFont(game->text, game->font);
    sfText_setPosition(game->text, textpos);
    sfText_setScale(game->text, scale);
    game->textwin = sfText_create();
    sfText_setFont(game->textwin, game->font);
    sfText_setPosition(game->textwin, textpos2);
    sfText_setScale(game->textwin, scale);
    game->textloose = sfText_create();
    sfText_setFont(game->textloose, game->font);
    sfText_setPosition(game->textloose, textpos2);
    sfText_setScale(game->textloose, scale);
    game->textpause = sfText_create();
    sfText_setFont(game->textpause, game->font);
    sfText_setPosition(game->textpause, textpos3);
    sfText_setScale(game->textpause, scale);
}

void set_fire(fond_t *fond, char **av, int ac, sfVector2f pos2)
{
    if (av[3][0] == 'f' && av[3][1] == 'i' &&
    av[3][2] == 'r' && av[3][3] == 'e') {
        fond->fox = create_object("images/fox2.png", pos2, fond->rectfox);
        my_putstr("Fire Fox\n");
    } else if (av[3][0] == 'i' && av[3][1] == 'c' && av[3][2] == 'e') {
        fond->fox = create_object("images/fox3.png", pos2, fond->rectfox);
        my_putstr("Ice Fox\n");
    } else
        fond->fox = create_object("images/fox.png", pos2, fond->rectfox);
}

void set_character(fond_t *fond, char **av, int ac)
{
    sfVector2f pos2 = {100, 380};
    if (ac < 3)
        fond->fox = create_object("images/fox.png", pos2, fond->rectfox);
    else if (ac == 3) {
        if (av[2][0] == 'f' && av[2][1] == 'i' &&
        av[2][2] == 'r' && av[2][3] == 'e') {
            fond->fox = create_object("images/fox2.png", pos2, fond->rectfox);
            my_putstr("Fire Fox\n");
        } else if (av[2][0] == 'i' && av[2][1] == 'c' && av[2][2] == 'e') {
            fond->fox = create_object("images/fox3.png", pos2, fond->rectfox);
            my_putstr("Ice Fox\n");
        } else
            fond->fox = create_object("images/fox.png", pos2, fond->rectfox);
    } else if (ac == 4) {
        set_fire(fond, av, ac, pos2);
    }
}