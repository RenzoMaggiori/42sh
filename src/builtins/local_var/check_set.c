/*
** EPITECH PROJECT, 2022
** B-PSU-200-BAR-2-1-42sh-renzo.maggiori
** File description:
** check_var.c
*/

#include "minishell.h"

void undefined_var(char *name_var)
{
    write(2, name_var, strlen(name_var));
    write(2, ": Undefined variable.\n", 23);
}

char **check_var_value(char *buf, char **var)
{
    for (int i = 0; var[i]; i++) {
        char **arr = str_to_word(var[i], ' ');
        if (str_equal(buf, arr[0])) {
            return (arr);
        }
        free_string_array(arr);
    }
    return (NULL);
}

char *save_name_var(char *buf)
{
    int j = 0;
    char *var = malloc(sizeof(char) * strlen(buf));
    for (int i = 1; buf[i]; i++, j++)
        var[j] = buf[i];
    var[j] = '\0';
    return (var);
}

char *check_set(char *buf)
{
    if (buf[0] != '$')
        return (buf);
    char **var = NULL;
    char *name_var = save_name_var(buf);
    if (get_file(".local_var") == NULL) {
        undefined_var(name_var);
        return (NULL);
    }
    var = str_to_word(get_file(".local_var"), '\n');
    char **arr = check_var_value(name_var, var);
    if (!arr) {
        undefined_var(name_var);
        return (NULL);
    }
    if (arr[1] && arr[2])
        return (arr[2]);
    else if (arr[1] && !arr[2])
        return (NULL);
    return buf;
}
