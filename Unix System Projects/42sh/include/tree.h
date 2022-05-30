/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-enzo.daumalle
** File description:
** tree.h
*/

#ifndef __TREE_H__
    #define __TREE_H__
    #define IN 0
    #define OUT 1

typedef struct tree_s {
    char *cmd;
    char *sep;
    int fd[2];
    struct tree_s *left;
    struct tree_s *right;
} tree_t;

#endif /* __TREE_H__ */
