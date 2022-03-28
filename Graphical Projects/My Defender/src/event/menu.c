/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** menu.c
*/

#include "my_defender.h"

void change_volume(game_t *game, button_t *button)
{
    if (game->sounds->volume == 100 && button->id == MUTE) {
        game->sounds->volume = 0;
        for (int i = 0; i != NB_MUSIC; i++)
            sfMusic_setVolume(game->sounds->music[i], game->sounds->volume);
        sfSprite_setTexture(button->sprite, button->texture_pressed, sfTrue);
    } else {
        game->sounds->volume = 100;
        for (int i = 0; i != NB_MUSIC; i++)
            sfMusic_setVolume(game->sounds->music[i], game->sounds->volume);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    }
}

void buttons_event(game_t *game, lnk_list_t *buttons)
{
    button_t *button = (button_t *) buttons->data;
    game->conf->next = 1;

    if (button->id == EXIT)
        sfSprite_setPosition(button->sprite, (sfVector2f) {130, 425});
    if (button->id == EXIT || button->id == PLAY || button->id == INFO ||
    button->id == MUTE)
        sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
    display_hover(game, button);
}

static void change_popup(game_t *game, button_t *button)
{
    char how_play[238] = "To place towers you had to use\
    the menu at\nyour disposal. The game is played ine waves,\n that is to say\
    that the difficulty will be increased\n at each turn. you have to defend\
    your city from\n the tank invasion. Good Luck Soldier.";
    char how_create_map[238] = "You can edit level map (in asset/map/level-x)\
    \nDo not change the length and width,\n keep the beginning of the path\
    \nin the first column (27).\nOtherwise you may have problems.";
    if (game->conf->next == 1 && button->id == POP_TEXTURE) {
        sfText_setString(game->text->popup, how_play);
        sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
        sfRenderWindow_drawText(game->window, game->text->popup, NULL);
    }
    if (game->conf->next == 2 && button->id == POP_TEXTURE) {
        sfText_setString(game->text->popup, how_create_map);
        sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
        sfRenderWindow_drawText(game->window, game->text->popup, NULL);
    }
    if (game->conf->next == 3 && button->id == POP_MAP)
        sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
}

void buttons_event_info(game_t *game, lnk_list_t *buttons)
{
    button_t *button = (button_t *) buttons->data;

    if (button->id == EXIT)
        sfSprite_setPosition(button->sprite, (sfVector2f) {260, 520});
    if (button->id == POP_TEXTURE || button->id == POP_MAP)
        sfSprite_setScale(button->sprite, (sfVector2f) {1.9, 1.9});
    if (button->id == EXIT || button->id == NEXT)
        sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
    change_popup(game, button);
    if (button_is_hover(game, button) && button->type == BUTTON)
        sfSprite_setTexture(button->sprite, button->texture_pressed, sfTrue);
    else if (!button_is_hover(game, button))
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
}

void buttons_event_map(game_t *game, lnk_list_t *buttons)
{
    button_t *button = (button_t *) buttons->data;
    char *map = convert_int_to_string(game->conf->set_map,
    game->conf->set_biome);

    sfText_setString(game->text->level, map);
    sfRenderWindow_drawText(game->window, game->text->level, NULL);
    if (button->id == EXIT)
        sfSprite_setPosition(button->sprite, (sfVector2f) {130, 520});
    if (button->id != EXIT && button->id != NEXT && button->id != BIOME &&
    button->id != PLAY && button->id != INFO &&
    button->id != MUTE && button->id != BAR)
        sfSprite_setScale(button->sprite, (sfVector2f) {1.9, 1.9});
    if (button->id == EXIT || button->id == NEXT || button->id == BIOME)
        sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
    if (button->id == RUN)
        sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
    display_hover(game, button);
}
