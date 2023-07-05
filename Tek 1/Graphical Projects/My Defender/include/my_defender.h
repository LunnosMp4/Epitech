/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** my_defender.h
*/

#ifndef MY_DEFENDER_H
    #define MY_DEFENDER_H
    #define UNUSED __attribute__((unused))
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include "sounds.h"
    #include "text.h"
    #include "config_game.h"
    #include "game.h"
    #include "utils.h"
    #include "object.h"
    #include "texture.h"
    #include "linked_list.h"
    #include "linked_ltype.h"
    #include "menu.h"

lnk_ltype_t *init_lnk_ltype(void);
game_t *init_game(sfVideoMode mode, sfColor clear_color);
menu_t *init_menu(game_t *game);
void init_objects(lnk_ltype_t *ltype);
void init_bar_buttons(lnk_ltype_t *ltype);
void create_type(utils_t utils, lnk_list_t **type);
void create_texture(utils_t utils, lnk_list_t **textures,
sfTexture *map);
void create_button(button_t utils, lnk_list_t **buttons);
void create_objects(utils_t utils, lnk_list_t **type, sfTexture *objects);
int load_map(lnk_ltype_t *ltype, game_t *game);
char *read_file(char *path);
int read_map(char *map, lnk_ltype_t *ltype, config_t *conf);
int check_map_isvalid(char *map, int i, sfVector2i);
void path_mobs(config_t *conf);
void process_list(lnk_list_t *list, game_t *game,
void (*pointer)(game_t *, lnk_list_t *));
void process_ltype(lnk_ltype_t *ltype, lnk_list_t *list, game_t *game,
void (*pointer)(game_t *, lnk_list_t *, lnk_ltype_t *));
void spawn_monster(lnk_ltype_t *ltype, game_t *game);
int process_game(game_t *game, lnk_ltype_t *ltype, menu_t *menu);
void process_sprite(game_t *game, lnk_list_t *list);
void process_menu(menu_t *menu, game_t *game);
void process_texture(game_t *game, lnk_list_t *list);
void process_menu_map(menu_t *menu, game_t *game);
void process_menu_info(menu_t *menu, game_t *game);
void process_window_events(game_t *game, lnk_ltype_t *ltype, menu_t *menu);
void process_game_button(game_t *game, lnk_list_t *buttons);
void build_towers(game_t *game, lnk_list_t *list, lnk_ltype_t *ltype);
void animation_mob(game_t *game, object_t *mob);
void turret_isclicked(game_t *game);
void turret_isreleased(game_t *game, lnk_ltype_t *ltype);
void buttons_event(game_t *game, lnk_list_t *buttons);
void buttons_event_info(game_t *game, lnk_list_t *buttons);
void buttons_event_map(game_t *game, lnk_list_t *buttons);
void replace_turret_btn(game_t *game, object_t *object);
int square_is_hover(game_t *game, int x, int y);
void display_hover(game_t *game, button_t *button);
int button_is_hover(game_t *game, button_t *button);
void destroy_game(game_t *game);
void destroy_object(game_t *game, lnk_list_t *list);
void add_node(void *data, lnk_list_t **head);
void next_page(int *state, int max);
void follow_cursor(game_t *game, sfSprite *sprite);
int my_getnbr(char const *str);
int my_numlen(int nb);
void my_putstr(char const *str);
char *convert_int_to_string(int lvl, int biome);
void change_volume(game_t *game, button_t *button);
void tank_animation(menu_t *menu);
int my_strlen(char *str);
char *my_strcat(char *dest , char const *src);
char *my_strncat(char *dest, char const *src, int nb);

#endif /* MY_DEFENDER_H */
