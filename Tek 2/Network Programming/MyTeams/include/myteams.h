/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** myteams.h
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


/* DONNER PAR EPITECH */
#define MAX_NAME_LENGTH         32
#define MAX_DESCRIPTION_LENGTH  255
#define MAX_BODY_LENGTH         512


#define MAX_BUFFER_SIZE         1024
#define NB_CMDS                 14
#define UNUSED                  __attribute__((unused))

/* CHECKER */
void check_args(int ac, char **av);

/* STR SPLIT IN ARGS */
typedef struct values_s {
    int i;
    int j;
    int k;
    int len;
} values_t;
char **split_args(char const *str, char sep);

int count_until(char *str, char *until);
char *str_append(char *dest, const char *src);
