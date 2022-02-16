/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-loic.tisseyre
** File description:
** my_functions.h
*/

int my_putstr(char const *str);
int analyse_events(game_t *game,
sfEvent event, entity_t *entity, animation_t *animation);
int manage_mouse_click(game_t *game, entity_t *entity);
void my_crosshair(game_t *game, entity_t *entity);
void set_spawn(sfRenderWindow *window, entity_t *entity);
void run_animation(animation_t *animation, game_t *game,
entity_t *entity, sfVector2f movex);
void close_window(sfRenderWindow *window);
game_t *create_game(sfVideoMode mode, game_t *game, sfColor clear_color);
void process_game(sfEvent event, game_t *game,
entity_t *entity, animation_t *animation);
void destroy_game(game_t *game, entity_t *entity, animation_t *animation);
void init_game(game_t *game, entity_t *entity, animation_t *animation);
void sinusoidal_movement(entity_t *entity , game_t *game);
void blood_explosion(animation_t *animation, game_t *game, entity_t *entity);