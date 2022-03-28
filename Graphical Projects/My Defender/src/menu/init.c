/*
** EPITECH PROJECT, 2021
** B-MUL-120-M4-2-1-mydefender-enzo.daumalle
** File description:
** init_buttons.c
*/

#include "my_defender.h"

void create_button(button_t utils, lnk_list_t **buttons)
{
    button_t *button = malloc(sizeof(button_t));

    button->texture = sfTexture_createFromFile(utils.path, NULL);
    if (utils.type == BUTTON)
        button->texture_pressed =
        sfTexture_createFromFile(utils.path_pressed, NULL);
    button->sprite = sfSprite_create();
    button->rect = utils.rect;
    button->pos = utils.pos;
    button->id = utils.id;
    button->type = utils.type;
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setColor(button->sprite, sfColor_fromRGBA(255, 255, 255, 220));
    add_node(button, buttons);
}

static void init_buttons_2(lnk_list_t **buttons)
{
    create_button((button_t) {"assets/img/menu/BackgroundPopUp.png", NULL,
    {0, 0, 220, 120}, {120, 40}, POP_TEXTURE, IMG, NULL, NULL, NULL}, buttons);
    create_button((button_t) {"assets/img/menu/ForwardUnpressed.png",
    "assets/img/menu/ForwardPressed.png", {0, 0, 220, 120},
    {650, 520}, NEXT, BUTTON, NULL, NULL, NULL}, buttons);
    create_button((button_t) {"assets/img/menu/NextUnpressed.png",
    "assets/img/menu/NextPressed.png", {0, 0, 220, 120},
    {390, 520}, BIOME, BUTTON, NULL, NULL, NULL}, buttons);
    create_button((button_t) {"assets/img/menu/BackgroundPopUp.png", NULL,
    {0, 0, 900, 450}, {120, 50}, RUN, IMG, NULL, NULL, NULL}, buttons);
    create_button((button_t) {"assets/img/menu/Bar.png", NULL,
    {0, 0, 1152, 100}, {0, 560}, BAR, IMG, NULL, NULL, NULL}, buttons);
}

static void init_buttons(lnk_list_t **buttons)
{
    create_button((button_t) {"assets/img/menu/PlayUnpressed.png",
    "assets/img/menu/PlayPressed.png", {0, 0, 240, 120},
    {130, 125}, PLAY, BUTTON, NULL, NULL, NULL}, buttons);
    create_button((button_t) {"assets/img/menu/CrossUnpressed.png",
    "assets/img/menu/CrossPressed.png", {0, 0, 240, 120},
    {130, 425}, EXIT, BUTTON, NULL, NULL, NULL}, buttons);
    create_button((button_t) {"assets/img/menu/InfoUnpressed.png",
    "assets/img/menu/InfoPressed.png", {0, 0, 240, 120},
    {130, 275}, INFO, BUTTON, NULL, NULL, NULL}, buttons);
    create_button((button_t) {"assets/img/menu/PausedPressed.png",
    "assets/img/menu/PausedUnpressed.png", {0, 0, 120, 120},
    {1000, 25}, MUTE, BUTTON, NULL, NULL, NULL}, buttons);
    create_button((button_t) {"assets/img/menu/Sample.png", NULL,
    {0, 0, 220, 120}, {120, 40}, POP_MAP, IMG, NULL, NULL, NULL}, buttons);
    init_buttons_2(buttons);
}

menu_t *init_menu(game_t *game)
{
    menu_t *menu = malloc(sizeof(menu_t));
    game->sounds->volume = 100;
    game->state = MENU;

    menu->buttons = NULL;
    init_buttons(&menu->buttons);
    menu->clock = sfClock_create();
    menu->rect = (sfIntRect) {0, 0, 600, 300};
    menu->texture_background = sfTexture_createFromFile(
    "assets/img/menu/TankSpritesheet.jpg", NULL);
    menu->sprite_background = sfSprite_create();
    sfSprite_setTexture(menu->sprite_background,
    menu->texture_background, sfTrue);
    sfSprite_setTextureRect(menu->sprite_background, menu->rect);
    sfSprite_setPosition(menu->sprite_background, (sfVector2f) {0, -70});
    sfSprite_scale(menu->sprite_background, (sfVector2f) {2, 2.5});
    return menu;
}
