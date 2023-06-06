/*
** EPITECH PROJECT, 2022
** B-PSU-200-BAR-2-1-42sh-renzo.maggiori
** File description:
** check_localvar.c
*/

#include "minishell.h"

void print_set_list(char **arr)
{
    for (int i = 0; arr[i]; i++)
        printf("%s\n", arr[i]);
}

int check_ifexist(char *name)
{
    char **var = str_to_word(get_file(".local_var"), '\n');
    for (int i = 0; var[i]; i++) {
        char **arr = str_to_word(var[i], ' ');
        if (strcmp(arr[0], name))
            return (-1);
    }
    return (0);
}

int check_localvar_name(char *s1, char *s2)
{
    if (s1 && (s1[0] < 65 || s1[0] > 122)) {
        write(2, "set: Variable name must begin with a letter.\n", 46);
        return (false);
    }
    if ((s2 && strlen(s2) > 1)) {
        write(2, "set: Variable name must begin with a letter.\n", 46);
        return (false);
    }
    if ((s2 && !str_equal(s2, "=")))
        return (false);
    return (true);
}

int edit_localvar_file(int fd, char **arg)
{
    if (!check_localvar_name(arg[1], arg[2]))
        return (false);
    for (int i = 1; arg[i]; i++) {
        write(fd, arg[i], strlen(arg[i]));
        write(fd, " ", 1);
        if (arg[i + 1] == NULL)
            write(fd, "\n", 1);
    }
    close(fd);
    return (true);
}

int set_command(char **arg, char ***env, int *ret)
{
    int fd = open(".local_var", O_WRONLY | O_APPEND | O_CREAT, 0644);
    (void)env;

    if (fd == ERROR)
        return (*ret = NOT_BUILTIN);
    if (!arg[1]) {
        print_set_list(str_to_word(get_file(".local_var"), '\n'));
        return ((*ret) = OK);
    }
    if (arg[1])
        if (!edit_localvar_file(fd, arg))
            return (*ret = HAS_ERROR);
    return ((*ret) = OK);
}
