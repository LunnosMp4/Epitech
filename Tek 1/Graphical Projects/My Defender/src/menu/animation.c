/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** global_menu.c
*/

#include "my_defender.h"

static void change_background(sfIntRect *rect)
{
    if (rect->top == 0)
        rect->top += 676 / 2;
    else
        rect->top = 0;
    rect->left = 0;
}

void display_hover(game_t *game, button_t *button)
{
    if (button_is_hover(game, button) && button->id != MUTE &&
    button->type == BUTTON)
        sfSprite_setTexture(button->sprite, button->texture_pressed, sfTrue);
    else if (!button_is_hover(game, button) && button->id != MUTE)
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
}

int button_is_hover(game_t *game, button_t *button)
{
    sfVector2f pos = sfSprite_getPosition(button->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if ((mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + button->rect.width)
    && (mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + button->rect.height))
        return 1;
    return 0;
}

int square_is_hover(game_t *game, int x, int y)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if ((mouse_pos.x >= x && mouse_pos.x <= x + 80)
    && (mouse_pos.y >= y && mouse_pos.y <= y + 80))
        return 1;
    return 0;
}

void tank_animation(menu_t *menu)
{
    menu->time = sfClock_getElapsedTime(menu->clock);
    menu->seconds = menu->time.microseconds / 1000000.0;
    if (menu->seconds > 0.11) {
        if (menu->rect.left >= (9000 - 600))
            change_background(&menu->rect);
        else {
            menu->rect.left = menu->rect.left + 600;
        }
    sfSprite_setTextureRect(menu->sprite_background, menu->rect);
    sfClock_restart(menu->clock);
    }
}
