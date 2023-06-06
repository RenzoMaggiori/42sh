/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** str_cut.c
*/

#include <stdlib.h>
#include <string.h>

char *str_cut(char *str, char c)
{
    char *str1 = malloc(sizeof(char) * strlen(str));
    int i = 0;
    int j = 0;

    while (str[i] != c)
        i++;
    i++;
    while (str[i]) {
        str1[j] = str[i];
        i++;
        j++;
    }
    str1[j] = '\0';
    return str1;
}
