/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** alias.c
*/

#include "minishell.h"

char *extra_alias(char **arr, char **alias)
{
    char *str = arr[1];
    char *enter = malloc(sizeof(char) * 2);
    char **arr1 = NULL;

    enter[0] = '\n'; enter[1] = '\0';
    for (int i = 2; arr[i]; i++) {
        str = strcat(str, arr[i]);
    } for (int j = 0; arr[j]; j++) {
        arr1 = str_to_word(alias[j], '\t');
        if (arr_len(alias) >= 2 && str_equal(str, arr1[0])) {
            write(2, "Alias loop.\n", 12);
            remove_enter(&enter, strlen(enter));
            return enter;
        }
    }
    return str;
}

char *check_alias(char *buf)
{
    char **alias = NULL;
    char **arr = NULL;

    if (get_file(".alias") == NULL)
        return buf;
    alias = str_to_word(get_file(".alias"), '\n');
    for (int i = 0; alias[i]; i++) {
        arr = str_to_word(alias[i], '\t');
        if (str_equal(buf, arr[0]) && arr[1])
            return (extra_alias(arr, alias));
    }
    return buf;
}

int edit_alias(char **alias, char **arg)
{
    if (arr_len(alias) < 2) return 1;
    int fd = open(".alias", O_WRONLY | O_CREAT, 0644);
    char **arr = NULL; char *str = str_cat(arg[1], "\t"); int j = -1;

    if (fd == ERROR) return 1;
    for (int i = 0; alias[i]; i++) {
        arr = str_to_word(alias[i], '\t');
        if (str_equal(arg[1], arr[0])) {
            j = i; break;
        }
    } for (int n = 2; arg[n]; n++) {
        if (arg[n + 1] == NULL) {
            str = strcat(str, arg[n]), str = strcat(str, "\n"); break;
        } str = strcat(str, arg[n]); str = strcat(str, " ");
    } if (j != -1) alias[j] = str;
    else
        return 1;
    for (int a = 0; alias[a]; a++) {
        write(fd, alias[a], strlen(alias[a]));
    } return 0;
}

int alias_command(char **arg, char ***env, int *ret)
{
    int fd = open(".alias", O_WRONLY | O_APPEND | O_CREAT, 0644);
    char **alias = str_to_word(get_file(".alias"), '\n');

    if (fd == ERROR)
        return (*ret = NOT_BUILTIN);
    (void)env;
    if (arg[1] == NULL) {
        for (int a = 0; alias[a]; a++) {
            write(1, alias[a], strlen(alias[a]));
            write(1, "\n", 1);
        } return ((*ret) = OK);
    } if (edit_alias(alias, arg) == 0) return ((*ret) = OK);
    for (int i = 1; arg[i]; i++) {
        write(fd, arg[i], strlen(arg[i]));
        if (arg[i + 1] != NULL && i == 1) write(fd, "\t", 1);
        if (arg[i + 1] != NULL && i != 1) write(fd, " ", 1);
        if (arg[i + 1] == NULL) write(fd, "\n", 1);
    }
    return ((*ret) = OK);
}
