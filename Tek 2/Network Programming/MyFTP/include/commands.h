/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-loic.tisseyre
** File description:
** commands.h
*/

#pragma once

#include "myftp.h"

/// @brief Handle the commands
struct command_t {
    char *name;
    bool (*func)(struct clients_data_t *, char *);
};

struct command_t commands[] = {
    {"USER", auth_username},
    {"PASS", auth_password},
    {"QUIT", quit},
    {"PASV", passive_mode},
    {"PORT", active_mode},
    {"HELP", display_help},
    {"NOOP", noop},
    {"CWD", cmd_cwd},
    {"CDUP", cmd_cdup},
    {"PWD", cmd_pwd},
    {"DELE", cmd_dele},
    {"LIST", cmd_list},
    {"RETR", cmd_retr},
    {"STOR", cmd_stor},
    {"RMD", cmd_rmd},
    {"MKD", cmd_mkd},
    {NULL, NULL}
};
