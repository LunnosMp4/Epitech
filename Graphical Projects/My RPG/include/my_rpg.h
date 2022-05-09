/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H
    #define MY_RPG_H
    #define UNUSED __attribute__((unused))

    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>

    #include "my.h"
    #include "progress_bar.h"
    #include "particles.h"
    #include "game.h"
    #include "utils.h"
    #include "event.h"
    #include "linked_list.h"
    #include "object.h"
    #include "text.h"
    #include "dialog.h"
    #include "linked_ltype.h"
    #include "menu.h"

//INIT
void init_ukr(lnk_ltype_t *ltype);
void init_front_russ(lnk_ltype_t *ltype, game_t *game);
void init_heal(lnk_ltype_t *ltype, game_t *game);
void init_structure(game_t *game);
void init_map_binary(game_t *game);
void create_buttons(menu_t *menu);
void create_sounds(game_t *game);
//PROCESS
void process_game(game_t *game, menu_t *menu, lnk_ltype_t *ltype);
particles_t *create_particles(sfVector2f size, lnk_list_t **list);
void process_menu(menu_t *menu, game_t *game);
void process_ingame(game_t *game, menu_t *menu, lnk_ltype_t *ltype);
void process_enemies(game_t *game, lnk_ltype_t *ltype,
lnk_list_t *list);
void process_allies(game_t *game, lnk_ltype_t *ltype,
lnk_list_t *list);
void process_chr(game_t *game, object_t *chr, lnk_ltype_t *ltype);
void process_poutine(game_t *game, lnk_ltype_t *ltype);
void process_interface(game_t *game, lnk_list_t *list);
void process_death(game_t *game, lnk_ltype_t *ltype, lnk_list_t *list);
void process_interface_popup(game_t *game,
object_t *object);
void process_inv_popup(game_t *game, object_t *object, sfVector2f min);

void process_quest_prologue(game_t *game,
object_t *object, sfVector2f min);
void process_quest_miel(game_t *game,
object_t *object, sfVector2f min);

void process_minimap(game_t *game, lnk_ltype_t *ltype);
void process_minimap_texts(game_t *game, lnk_list_t *list);
void lifebar_texts(game_t *game, lnk_ltype_t *ltype, text_t *text);
void process_texts(game_t *game, lnk_list_t *list);
void process_settings(menu_t *menu, game_t *game);
void process_pause(menu_t *menu, game_t *game);
void process_effects(game_t *game, lnk_ltype_t *ltype, lnk_list_t *list);
void process_game_over(game_t *game, lnk_list_t *list);
void process_win(game_t *game, lnk_list_t *list);
//ANIMATION
void algo_fight(lnk_list_t *list, lnk_ltype_t *ltype, game_t *game);
void change_face_dialog(dialog_t *dialog);
void display_dialog(game_t *game, dialog_t *dialog, lnk_ltype_t *ltype);
void lifebar(game_t *game, lnk_ltype_t *ltype);
void day_cycle(game_t *game);
void set_entity_direction(object_t *entity, sfVector2f pentity);
void limited_move(object_t *entity, sfVector2f move, game_t *game);
void anime_sprite(object_t *object, sfVector2f nbfrm, float frame);
void follow(object_t *entity, sfVector2f ptarget, sfVector2f pentity,
game_t *game);
void flee(object_t *entity, sfVector2f ptarget, sfVector2f pentity,
game_t *game);
void gui_texts(game_t *game, lnk_ltype_t *ltype, lnk_list_t *list);
void weapon_direction_y(game_t *game, object_t *entity, sfVector2f pos);
void weapon_direction_x(game_t *game, object_t *entity, sfVector2f pos);
void weapon_direction_x2(game_t *game, object_t *entity, sfVector2f pos);
void set_poutine_direction(object_t *entity, sfVector2f pentity);
void set_human_x(object_t *entity,
sfVector2f pentity, sfVector2f pentity2);
void set_human_y(object_t *entity,
sfVector2f pentity, sfVector2f pentity2);
//EVENT
void ingame_events(game_t *game, lnk_ltype_t *ltype);
void menu_events(game_t *game, menu_t *menu, lnk_list_t *list);
void settings_events(game_t *game, menu_t *menu, lnk_list_t *list);
void pause_events(game_t *game, lnk_list_t *list);
void history(game_t *game, lnk_ltype_t *ltype);
void inventory(game_t *game, object_t *chr);
void dialog_event(game_t *game, lnk_ltype_t *ltype, char *topic);
void event_types(object_t *allie, event_t *event, lnk_list_t *list);
bool entity_in_area(object_t *object, sfVector2f target, float area);
void on_move_player(game_t *game, object_t *object);
void change_map(lnk_ltype_t *ltype, game_t *game);
void shoot(game_t *game, object_t *entity, lnk_list_t **effects);
void hurt(object_t *entity);
void map_ingame(game_t *game, menu_t *menu, lnk_ltype_t *ltype);
sfVector2f spawn_random(int begin, int end, game_t *game);
void ingame_events_pt2(game_t *game, lnk_ltype_t *ltype);
void exit_game_escape(game_t *game);
//DESTROY
void destroy_game(game_t *game);
void destroy_menu(menu_t *menu, lnk_ltype_t *ltype);
void destroy_object(game_t *game, lnk_ltype_t *ltype,
lnk_list_t *list);
//UTILS
float get_seconds(sfClock *clock, sfTime time);
bool ishover(game_t *game, object_t *object);
char **str_to_word_array(char const *str);
int my_strlen(char const *str);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
char **split_string(char const *str, char sep);
int to_number(char const *str);
char *convert_int_to_text(int life, char *str);
char *convert_int(int str, char *digit, char *arg);
void create_garnison_allie(utils_t utils,
lnk_ltype_t *ltype, sfVector2i size);
void create_garnison_enemy(utils_t utils,
lnk_ltype_t *ltype, sfVector2i size);
attribute_t *set_stats_weapon(TYPE type);
void select_types(utils_t utl, sfTexture *texture, object_t *object);
void weapon_ak(TYPE type, attribute_t *stats);
void weapon_glock(TYPE type, attribute_t *stats);
void weapon_sniper(TYPE type, attribute_t *stats);
//Linked_list
void process_ltype(game_t *game, lnk_ltype_t ltype, lnk_list_t **list,
void (*pointer)(game_t *, lnk_ltype_t *, lnk_list_t *));
void process_lmenu(game_t *game, menu_t *menu, lnk_list_t *list,
void (*pointer)(game_t *, menu_t *, lnk_list_t *));
void process_list(game_t *game, lnk_list_t *list,
void (*pointer)(game_t *, lnk_list_t *));
void add_node(void *data, lnk_list_t **head);
void delete_node(lnk_list_t **node);
//Parsing
char *read_file(char *path);
char **parsing_arg(char *buffer);
void link_params_entity(char **tab);
void link_params_entity(char **tab);
void link_params_char(char **tab);

#endif /* MY_RPG_H */
