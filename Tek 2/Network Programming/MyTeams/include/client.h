/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-enzo.daumalle
** File description:
** client.h
*/

#pragma once

#include "myteams.h"
#include "../libs/myteams/logging_client.h"

/* DEFINE */
#define PARAMS_CMDS             client_t *client, char *buffer
#define PARAMS_CMDS_UNUSED      UNUSED client_t *client, UNUSED char *buffer
#define IP_ADDRESS              1
#define PORT                    2
#define OK                    0
#define ERROR                 1
#define UNAUTHORIZED          2

/* RESPONSE FROM THE SERVER */
typedef struct response_s {
    int code;
    char *message;
    char **args;
} response_t;

/* CLIENT */
typedef struct client_s {
    int fd;
    char *ip;
    int port;
    struct sockaddr_in serv_addr;
    char *username;
    uuid_t uuid;
    response_t *response;
} client_t;
client_t *init_client(void);

/* COMMANDS */
typedef struct builtin_s {
    char *cmd;
    void (*fptr) (PARAMS_CMDS);
} builtin_t;
/// @brief Get the builtin object of the command
/// @param buffer Line of the client
/// @return The builtin object to execute the function
builtin_t *get_builtin(char *buffer);
void create_cmd(PARAMS_CMDS);
void help_cmd(PARAMS_CMDS);
void info_cmd(PARAMS_CMDS);
void list_cmd(PARAMS_CMDS);
void login_cmd(PARAMS_CMDS);
void logout_cmd(PARAMS_CMDS);
void messages_cmd(PARAMS_CMDS);
void send_cmd(PARAMS_CMDS);
void subscribe_cmd(PARAMS_CMDS);
void subscribed_cmd(PARAMS_CMDS);
void unsubscribe_cmd(PARAMS_CMDS);
void use_cmd(PARAMS_CMDS);
void user_cmd(PARAMS_CMDS);
void users_cmd(PARAMS_CMDS);


void connection(client_t *client);
int wait_response(client_t *client);
void send_to_server(char *command_name, char *buffer,
char *command_code, client_t *client);
