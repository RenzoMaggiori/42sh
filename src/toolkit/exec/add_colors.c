/*
** EPITECH PROJECT, 2022
** B-PSU-200-BAR-2-1-42sh-renzo.maggiori
** File description:
** add_colors.c
*/

#include "minishell.h"

void print_array(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        printf("%s\n", arr[i]);
    }
}

char **add_colors(char *prompt, char ***arg)
{
    if (strcmp(prompt, "ls") != 0 && strcmp(prompt, "grep") != 0)
        return ((*arg));
    (*arg) = concat_str_array((*arg), "--color=auto");
    return ((*arg));
}
