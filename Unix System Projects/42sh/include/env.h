/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** env.h
*/

#ifndef __ENV_H__
    #define __ENV_H__
    #define ENV   0
    #define ALIAS 1

typedef struct env_s {
    char *key;
    char *value;
    int id;
    char **env_array;
    struct env_s *next;
} env_t;

#endif /* __ENV_H__ */
