/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** manage_executable
*/

#include "minishell.h"

void set_last_exit(int *last_return, pid_t pid)
{
    waitpid(pid, last_return, WUNTRACED);
    if (WIFEXITED((*last_return)))
        (*last_return) = WEXITSTATUS((*last_return));
}

int execute_binary(char *exec, char **arg, char **env, int *last_return)
{
    pid_t child = fork();

    if (child == 0) {
        if ((execve(exec, arg, env)) == ERROR) {
            print_error(exec), print_error(": ");
            print_error(strerror(errno)), print_error(BIN_NOT_EXEC);
            exit ((*last_return) = OK);
        }
    } else
        set_last_exit(last_return, child);
    if (is_printable_signal((*last_return)))
        print_signal_out((*last_return)), (*last_return) = OK;
    return ((*last_return));
}

bool try_executable(char **exec, char **arg, char **env, int *last_return)
{
    int exec_status = (is_executable(exec, arg, env));

    if (exec_status == NONE || is_directory((*exec))) {
        return (false);
    } else
        execute_binary((*exec), arg, env, last_return);
    return (true);
}
