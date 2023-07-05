/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** split_args.c
*/

#include "myteams.h"

static void count_in_quote(char const *str, values_t *v)
{
    v->j = v->i + 1;
    while (v->j < v->len && str[v->j] != '"') {
        v->j++;
    }
}

static void copy_in_quote(char const *str, values_t *v, char **result)
{
    result[v->k] = malloc(sizeof(char) * (v->j - v->i));
    strncpy(result[v->k], &str[v->i + 1], v->j - v->i - 1);
    result[v->k][v->j - v->i - 1] = '\0';
    v->k++;
    v->i = v->j + 1;
}

static void find_end_of_word(char const *str, values_t *v,
char **result, char sep)
{
    v->j = v->i + 1;
    while (v->j < v->len && str[v->j] != sep) {
        if (str[v->j] == '"') {
            v->j++;
            count_in_quote(str, v);
        }
        v->j++;
    }
    result[v->k] = malloc(sizeof(char) * (v->j - v->i + 1));
    strncpy(result[v->k], &str[v->i], v->j - v->i);
    result[v->k][v->j - v->i] = '\0';
    v->k++;
    v->i = v->j;
}

static bool loop_split_args(char const *str, values_t *v,
char **result, char sep)
{
    if (str[v->i] == '"') {
        count_in_quote(str, v);
        if (v->j >= v->len)
            return false;
        copy_in_quote(str, v, result);
    } else if (str[v->i] == sep)
        v->i++;
    else
        find_end_of_word(str, v, result, sep);
    return true;
}

char **split_args(char const *str, char sep)
{
    char** result = malloc(sizeof(char*) * 10);
    values_t *v = malloc(sizeof(values_t));
    v->len = strlen(str);
    v->i = 0;
    v->j = 0;
    v->k = 0;

    while (v->i < v->len)
        if (loop_split_args(str, v, result, sep) == false)
            break;

    result[v->k] = NULL;
    return result;
}
