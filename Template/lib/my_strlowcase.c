/*
** EPITECH PROJECT, 2021
** my_strlowcase.c
** File description:
** low case
*/

char *my_strlowcase(char * str)
{
    int arg = 0;

    for (arg; str[arg] != '\0'; arg++) {
        if (str[arg] >= 65 && str[arg] <= 90) {
            str[arg] = str[arg] + 32;
        }
    }
    return (str);
}
