/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** server.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <sys/queue.h>
#include <uuid/uuid.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>
#include <math.h>
#include <mqueue.h>
#include <fcntl.h>
#include <errno.h>

#define PARAMS_FEATS            server_t *s
#define NB_CMDS                 24
#define FD                      s->client->sockfd

/* NETWORK */
/*---------*/

/* Client */
enum Status {
    GUI,
    AI
};

typedef struct commands_order_s {
    char *command;
    char **args;
    int fd;
    struct timeval asked_timer;
    double good_time;
    struct commands_order_s *next;
} commands_order_t;

typedef struct request_s {
    int code;
    char **args;
    int nb_args;
    int context;
} request_t;

typedef struct inventory_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory_t;

typedef struct clients_s {
    int sockfd;
    int number;
    int lv;
    int orientation;
    int x;
    int y;
    struct timeval born_timer;
    inventory_t *inv;
    char *name_team;
    bool is_dead;
    request_t *request;
    enum Status status;
    struct clients_s *next;
} clients_t;

typedef struct map_s {
    char *players;
    int x;
    int y;
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    struct map_s *next;
} map_t;

typedef struct look_s {
    int max_items;
    int visionSize;
    int totalTiles;
    char **tiles;
    int tileX;
    int tileY;
    char *tileString;
    map_t* current;
} look_t;

/* Server */
typedef struct server_s {
    int sockfd;
    int port;
    int width;
    int height;
    int gui_fd;
    int next_number;
    char **nameX;
    int *players_in_teams;
    int clientsNb;
    int freq;
    clients_t *clients;
    clients_t *client;
    map_t *tiles;
    int *resources_data;
    commands_order_t *cmd;
} server_t;

//client_actions.c
int client_length(clients_t *list);
clients_t *add_client_front(server_t *s, clients_t *list, int fd, char **n);
void delete_client(clients_t **list, int fd);
void client_set(clients_t *list_client, fd_set *readfds);
void clear_request(request_t *request);

//client_actions2.c
void ai_or_gui(server_t *s, clients_t **client, char **n, int fd);
void ai_or_gui_actions(server_t **s, clients_t **current, char *name_buffer);

//client_inventory.c
void init_inventory(inventory_t **inv);

//resources.c
map_t *setup_resources_in_map(map_t *tiles, int *resources_data,
int width, int height);

//init_server_params.c
int init_map_params(server_t *server, char **av, int i);
void init_basics_params(server_t *server, char **av);

//init_server.c
server_t *init_server(int sockfd, char **av);

//management.c
void client_management(server_t *server, fd_set *readfds);
void ret_management(server_t *server, int sockfd, fd_set *readfds);

//server_actions.c
void listen_for_connections(int sockfd);
int accept_connection(int sockfd);
void handle_connection(server_t *s, char *buffer);
void manage_request(server_t *s, char *buffer);

//signal.c
void handleCtrlC(int signal);
void handleCtrlD(int signal);

//start_server.c
void start_server(char **av);
/*---------*/


/* COMMANDS */
/*----------*/

/* Ai */
//args_tester.c
bool command_args_good_extra(char *command, char **args);
bool command_args_good_info(char *command, char **args);
bool command_args_good_move(char *command, char **args);

//extra_real.c
void set_r(PARAMS_FEATS, int fd);
void fork_r(PARAMS_FEATS, int fd);
void incantation_r(PARAMS_FEATS, int fd);
void eject_r(PARAMS_FEATS, int fd);
void take_r(PARAMS_FEATS, int fd);

//extra.c
void set(PARAMS_FEATS);
void fork_f(PARAMS_FEATS);
void incantation(PARAMS_FEATS);
void eject(PARAMS_FEATS);
void take(PARAMS_FEATS);

//forward.c
int forward_north(int y, int max_y);
int forward_east(int y, int max_y);
int forward_south(int x, int max_x);
int forward_west(int x, int max_x);

//has_items.c
int has_item_set(clients_t *player, commands_order_t *args);
int has_item_take(map_t *current_map, commands_order_t *args);

//incantation.c
bool can_incantation(server_t *s, clients_t *player, map_t *map);

//info_real.c
void broadcast_r(PARAMS_FEATS, int fd);
void connect_nbr_r(PARAMS_FEATS, int fd);
void look_r(PARAMS_FEATS, int fd);
void inventory_r(PARAMS_FEATS, int fd);

//info.c
void broadcast(PARAMS_FEATS);
void connect_nbr(PARAMS_FEATS);
void look(PARAMS_FEATS);
void inventory(PARAMS_FEATS);

//look.c
char *generate_looked_string(map_t* map, int level);

//move_real.c
void forward_r(PARAMS_FEATS, int fd);
void right_r(PARAMS_FEATS, int fd);
void left_r(PARAMS_FEATS, int fd);

//move.c
void forward(PARAMS_FEATS);
void right(PARAMS_FEATS);
void left(PARAMS_FEATS);

//set_take.c
int has_item_set(clients_t *player, commands_order_t *args);
int has_item_take(map_t *current_map, commands_order_t *args);
void drop_item(clients_t **player, map_t **current_map, int opt);
void take_item(clients_t **player, map_t **current_map, int opt);

/* Gui*/
//extra.c
void msz(PARAMS_FEATS, clients_t *current);
void sgt(PARAMS_FEATS, clients_t *current);
void plv(PARAMS_FEATS, clients_t *current);
void sst(PARAMS_FEATS, clients_t *current);

//info.c
void pnw(PARAMS_FEATS, clients_t *current);
void bct(PARAMS_FEATS, clients_t *current);
void mct(PARAMS_FEATS, clients_t *current);
void tna(PARAMS_FEATS, clients_t *current);
void pin(PARAMS_FEATS, clients_t *current);

//move.c
void ppo(PARAMS_FEATS, clients_t *current);

//send_to_gui
void send_to_gui(server_t *server, clients_t *current);
map_t *find_which_tile(map_t *map_list, int x, int y);
void find_which_map(server_t **map_list, int x, int y);
void random_pos(server_t **server, clients_t **current);

/* Select */
//extra.c
int select_extra_commands(char *user_command);
int select_extra_gui(char *user_command);
//global_select.c
int which_command(char *user_command);
//gui_select.c
bool check_request_gui(server_t *s);
//info.c
int select_info_commands(char *user_command);
//move.c
int select_move_commands(char *user_command);

//death.c
void check_death_players(server_t *s, clients_t **client, int timer);

//find.c
int find_team(char **list_team, char *team);

//global_commands.c
typedef void (*command_handler)(server_t *);
extern const command_handler commands[];
typedef void (*commands_no_timer)(server_t *, int);
extern const commands_no_timer real_commands[];
typedef void (*command_gui)(server_t *, clients_t *);
extern const command_gui gui_commands[];
void time_command(char *message, int time);
void if_command(int code);

//real_commands.c
void check_commands_up(server_t *s);
/*----------*/


/* ERROR_HANDLING */
/*----------------*/

//check_args.c
char **check_args(char **args, int nb, int port, int width);
bool check_request(server_t *s);
int if_can_run_serv(char **av, int ac);

//check_args2.c
void check_port(int port);
void check_map_size(int w, int h);
void check_freq(int freq);
void check_clients_nb(int clt);
void check_all(int port, int with, int height, int clientNb);

//set_params.c
void set_xy_params(char **args, int nb, int *w, int *h);
int set_pcf_params(char **args, int nb, int *port, int *clientNb);

//sig_handler.c
void sig_handler(int signo);
/*----------------*/


/* PARSING*/
/*--------*/

//args_management.c
char *get_command(char **str);
char **get_args(char **dest, char *src, int spaces_nb);
char **split_args(char *str);

//parse_functions.c
void parse_request(server_t *s, char *response);
/*--------*/


/* UTILS */
/*-------*/

//count_somethings.c
int how_many_lines(char **array);
int count_until(char *str, char *until);
int space_counter(char *str);

//double_array.c
void add_space(char *str);
char **copy_double_array(char** src, int index);

//is_somethings.c
bool is_in_array(char **array, char *str);
bool is_only_digits(char *str);
bool is_item(char *item);

//linked_list.c
clients_t *find_item(clients_t *list, int fd);
void remove_command(commands_order_t **list, char *to_find, int fd);
void add_cmd(commands_order_t **l, char *c, char **args, int fd,
struct timeval a, double g);
void init_linked_list(map_t **list);
void init_map(map_t** list, int x, int y);
void print_linked_map(map_t *tiles);

//linked_list2.c
void remove_command2(commands_order_t **current, commands_order_t **prev,
commands_order_t **list);
clients_t *find_id(clients_t *client, int id);
map_t *find_map(map_t *tiles, int x, int y);

//my_put.c
void my_putstr(const char *str);

//free_all.c
char **free_new_args(char **new_args, char **new_new_args);
void free_all(server_t *server);

//string_management.c
char *str_append(char *dest, const char *src);
void clear_string(char *str);
char *to_string(int number);
char *remove_back_n(char *str);
char *my_strcat(const char *str1, const char *str2);

//teams_management.c
int *init_teams(int max_players);
int is_good_name_team(char **name_list, char *name);
/*-------*/


/* STR SPLIT IN ARGS */
typedef struct values_s {
    int i;
    int j;
    int k;
    int len;
} values_t;
