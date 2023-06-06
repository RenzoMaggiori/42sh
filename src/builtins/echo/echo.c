/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** echo
*/

#include "minishell.h"

int echo_command(char **arg, char ***env, int *ret)
{
    (void)env;
    int i = 1;
    bool n = false;

    for (; arg[i]; i++) {
        if (!n && str_equal(arg[i], "-n")) {
            n = true; continue;
        }
        if (arg[i][0] == '$') {
            char *env_var = check_set(arg[i]);
            put_string(env_var); continue;
        }
        put_string(arg[i]);
        if (arg[i + 1]) put_string(" ");
    }
    if (!n) put_string("\n");
    *ret = 0;
    return (SUCCESS);
}
