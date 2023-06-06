/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** misc_tools
*/

#include "minishell.h"

int is_executable(char **exec, char **arg, char **env)
{
    if (!(has_character(arg[0], '/')) && is_path_exec(exec, arg, env))
        return (PATH_BIN);
    if (is_local_exec((*exec)))
        return (LOCAL_BIN);
    return (NONE);
}

bool is_exec_command(char *path)
{
    char *path_cmd = get_path_from_name(path);

    if (is_directory(path_cmd)) {
        free(path_cmd);
        return (true);
    }
    free(path_cmd);
    return (false);
}

void access_error_print(char *program, int *last_return)
{
    print_error(program);
    if ((file_exists(program) && no_permissions(program))
        || (file_exists(program) && has_character(program, '/')))
        print_error(PERSMISSION_DENIED), (*last_return) = OK;
    else
        print_error(CMD_NOT_FOUND), (*last_return) = EXIT_FAIL;
    free(program);
}

char *get_input_arguments(int prev_ret)
{
    char *input = get_input_string(prev_ret);
    return (input);
}
