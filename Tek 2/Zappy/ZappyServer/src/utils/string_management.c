/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** lines
*/

#include "server.h"

char *str_append(char *dest, const char *src)
{
    size_t dest_len = dest != NULL ? strlen(dest) : 0;
    size_t src_len = strlen(src);
    size_t new_size = dest_len + src_len + 1;

    dest = realloc(dest, new_size);
    if (dest == NULL)
        return NULL;
    memcpy(dest + dest_len, src, src_len + 1);
    return dest;
}

void clear_string(char *str)
{
    if (str != NULL) {
        memset(str, '\0', strlen(str));
        free(str);
    }
}

char *to_string(int number)
{
    int length = snprintf(NULL, 0, "%d", number);
    char *str = malloc(sizeof(char) * (length + 1));
    snprintf(str, length + 1, "%d", number);
    return str;
}

char *remove_back_n(char *str)
{
    size_t len = strlen(str);
    char *filtered_str = (char*) malloc((len + 1) * sizeof(char));
    size_t j = 0;

    for (size_t i = 0; i < len; i++) {
        if (isprint(str[i])) {
            filtered_str[j++] = str[i];
        }
    }

    filtered_str[j] = '\0';
    return filtered_str;
}

char *my_strcat(const char *str1, const char *str2)
{
    int len1 = 0;
    int len2 = 0;
    int i = 0;
    int j = 0;
    while (str1[len1] != '\0') {
        len1++;
    }
    while (str2[len2] != '\0') {
        len2++;
    }
    char *result = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
    for (; i < len1; i++) {
        result[i] = str1[i];
    }
    for (; j < len2; j++) {
        result[i + j] = str2[j];
    }
    result[i + j] = '\0';
    return result;
}
