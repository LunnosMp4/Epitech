/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** menu.c
*/

#include "my_defender.h"

void process_menu(menu_t *menu, game_t *game)
{
    tank_animation(menu);
    sfRenderWindow_drawSprite(game->window, menu->sprite_background, NULL);
    process_list(menu->buttons, game, buttons_event);
}

void process_menu_info(menu_t *menu, game_t *game)
{
    tank_animation(menu);
    sfRenderWindow_drawSprite(game->window, menu->sprite_background, NULL);
    process_list(menu->buttons, game, buttons_event_info);
}

void process_menu_map(menu_t *menu, game_t *game)
{
    tank_animation(menu);
    sfRenderWindow_drawSprite(game->window, menu->sprite_background, NULL);
    process_list(menu->buttons, game, buttons_event_map);
}
