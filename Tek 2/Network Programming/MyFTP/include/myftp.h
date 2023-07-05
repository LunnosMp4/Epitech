/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-loic.tisseyre
** File description:
** include.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>


#define QUEUE_LEN 5
#define BUF_SIZE 1024
#define MAX_CLIENTS 100
#define UNUSED __attribute__((unused))

/// @brief Structure for the server address
/// @param sin_family The family of the address
/// @param sin_port The port of the address
/// @param sin_addr The address
struct sockaddr_in_t {
    sa_family_t sin_family;
    in_port_t sin_port;
    struct in_addr sin_addr;
};

struct clients_data_t {
    int fd;
    int data_fd;
    int data_port;
    bool is_logged;
    char *username;
    bool is_passive;
    bool is_active;
    char *anonymous_path;
    char *current_path;
};

/// @brief Start the server
/// @param port The port to listen to
/// @param path The path where Anonymous can access
void start_server(int port, char *path);

/// @brief Accept a connection
/// @param net_socket The socket of the server
/// @param path The path where Anonymous can access
/// @param clients The clients connected
void accept_connection(int net_socket, char *path);

struct help_struct_t {
    const char *name;
    const char *help;
};

/******* Commands Functions *******/

bool auth_username(struct clients_data_t *client, char *username);
bool auth_password(struct clients_data_t *client, char *password);
bool quit(struct clients_data_t *client, char *args);
bool passive_mode(struct clients_data_t *client, char *args);
bool active_mode(struct clients_data_t *client, char *args);
bool display_help(struct clients_data_t *client, char *args);
bool noop(struct clients_data_t *client, char *args);
bool cmd_cwd(struct clients_data_t *client, char *args);
bool cmd_cdup(struct clients_data_t *client, UNUSED char *args);
bool cmd_pwd(struct clients_data_t *client, UNUSED char *args);
bool cmd_dele(struct clients_data_t *client, char *args);
bool cmd_list(struct clients_data_t *client, char *args);
bool cmd_retr(struct clients_data_t *client, UNUSED char *args);
bool cmd_stor(struct clients_data_t *client, char *args);
bool check_commands(struct clients_data_t *client,
char *args, bool need[3], int expt);
bool cmd_rmd(struct clients_data_t *client, char *args);
bool cmd_mkd(struct clients_data_t *client, char *args);
