/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** which
*/

#include "minishell.h"

bool get_path(char **exec, char **arg, char **env)
{
    char *var = find_env_var("PATH", env);
    char **paths = str_to_word(var, ':'), *bin_path = NULL;
    int a = 0;

    if (!var || !paths || !arg)
        return (false);
    free(var);
    while (paths[a] && (*exec)) {
        bin_path = fill_bin_path((*exec), paths[a]);
        if (can_be_executed(bin_path)) {
            free((*exec)), (*exec) = str_dup(bin_path);
            free(bin_path), free_string_array(paths);
            return (true);
        }
        free(bin_path);
        a++;
    }
    free_string_array(paths);
    return (false);
}

int which_command(char **arg, char ***env, int *ret)
{
    (void)env;
    if (!arg[1]) {
        *ret = 1;
        return (SUCCESS);
    }
    char *path = NULL;
    for (int i = 1; arg[i]; i++) {
        if (is_builtin(arg[i])) {
            put_string(arg[i]);
            put_string(" is a shell built-in\n");
            continue;
        }
        if (get_path(&arg, arg, *env)) {
            put_string(path);
            put_string("\n");
            free(path);
        }
    }
    *ret = 0;
    return (SUCCESS);
}
