/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** server.h
*/

#pragma once


#include "myteams.h"
#include "../libs/myteams/logging_server.h"

#define PORT                    1
#define PARAMS_FEATS            server_t *s
#define PARAMS_FEATS_UNUSED     UNUSED server_t *s
#define FD                      s->client->sockfd
#define CTX_NULL                0
#define CTX_TEAM                1
#define CTX_TEAM_CHANNEL        2
#define CTX_TEAM_CHANNEL_THREAD 3


/* REQUEST FROM THE SERVER */
typedef struct request_s {
    int code;
    char **args;
    int nb_args;
    int context;
    char *uuid_team;
    char *uuid_channel;
    char *uuid_thread;
} request_t;


/* TEAMS */
typedef struct teams_s {
    char *name;
    char *description;
    uuid_t uuid;
    struct teams_s *next;
} teams_t;

teams_t *add_team(teams_t *list, char *name,
char *description, uuid_t uuid);
void remove_team(teams_t *list, teams_t *team);
teams_t *find_team_by_name(teams_t *list, char *name);
teams_t *find_team_by_uuid(teams_t *list, char *uuid);


/* CHANNELS */
typedef struct channels_s {
    char *name;
    char *description;
    uuid_t uuid;
    teams_t *team;
    struct channels_s *next;
} channels_t;

channels_t *add_channel(channels_t *list, char **args,
uuid_t uuid, teams_t *team);
void remove_channel(channels_t *list, channels_t *channel);
channels_t *find_channel_by_name(channels_t *list, char *name);
channels_t *find_channel_by_uuid(channels_t *list, char *uuid);


/* THREADS */
typedef struct threads_s {
    char *title;
    char *message;
    uuid_t uuid_author;
    uuid_t uuid;
    time_t timestamp;
    channels_t *channel;
    struct threads_s *next;
} threads_t;

threads_t *add_thread(threads_t *list, char **args,
uuid_t *uuid_list, channels_t *channel);
void remove_thread(threads_t *list, threads_t *thread);
threads_t *find_thread_by_title(threads_t *list, char *title);
threads_t *find_thread_by_uuid(threads_t *list, char *uuid);

/* COMMENTS */
typedef struct comments_s {
    char *message;
    uuid_t uuid;
    threads_t *thread;
    struct comments_s *next;
} comments_t;


/* SUBSCRIPTIONS */
typedef struct subscriptions_s {
    uuid_t uuid_user;
    teams_t *team;
    struct subscriptions_s *next;
} subscriptions_t;


/* MESSAGES */
typedef struct messages_s {
    uuid_t uuid_author;
    char *message;
    struct messages_s *next;
} messages_t;


/* CLIENTS */
typedef struct clients_s {
    int sockfd;
    char *username;
    bool is_logged;
    uuid_t uuid;
    request_t *request;
    struct clients_s *next;
} clients_t;


/* SERVER */
typedef struct server_s {
    int sockfd;
    int port;
    clients_t *clients;
    clients_t *client;
    teams_t *teams;
    channels_t *channels;
    threads_t *threads;
    comments_t *comments;
    subscriptions_t *subscriptions;
    messages_t *messages;
} server_t;
server_t *init_server(int port, int sockfd);

int client_length(clients_t *list);
clients_t *add_client_front(clients_t *list, int fd);
void delete_client(clients_t **list, int fd);
void start_server(int port);
void client_set(clients_t *list_client, fd_set *readfds);
void handle_connection(server_t *server, fd_set *readfds);
int accept_connection(int sockfd);
void listen_for_connections(int sockfd);
void wait_request(char *buffer, server_t *s);


/* FEATURES */
void use(PARAMS_FEATS);
void login(PARAMS_FEATS);
void logout(PARAMS_FEATS);
void users(PARAMS_FEATS);
void user(PARAMS_FEATS);
void send_message(PARAMS_FEATS);
void messages(PARAMS_FEATS);
void subscribed(PARAMS_FEATS);
void subscribe(PARAMS_FEATS);
void unsubscribe(PARAMS_FEATS);

/* Create */
void create(PARAMS_FEATS);
void create_team(PARAMS_FEATS);
void create_channel(PARAMS_FEATS);
void create_thread(PARAMS_FEATS);
void create_reply(PARAMS_FEATS);

/* List */
void list(PARAMS_FEATS);
void list_team(PARAMS_FEATS);
void list_channel(PARAMS_FEATS);
void list_thread(PARAMS_FEATS);
void list_reply(PARAMS_FEATS);

/* Info */
void info(PARAMS_FEATS);
void info_team(PARAMS_FEATS);
void info_thread(PARAMS_FEATS);
void info_user(PARAMS_FEATS);
void info_channel(PARAMS_FEATS);

void help(PARAMS_FEATS);

typedef void (*command_handler)(server_t*);
