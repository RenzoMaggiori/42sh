/*
** EPITECH PROJECT, 2022
** B-PSU-200-BAR-2-1-42sh-renzo.maggiori
** File description:
** and_cmd.c
*/

#include "minishell.h"

bool command_has_error(cmd_tree_t *tree, int *ret, bool and_cmd)
{
    if ((!and_cmd && (no_right_stem(tree) || no_left_stem(tree)))
        || (and_cmd && no_right_stem(tree))) {
        print_error(INVALID_NULL), (*ret) = EXIT_FAIL;
        return (true);
    }
    return (false);
}

int and_command(cmd_tree_t *tree, char ***env, int *last_return)
{
    if ((no_left_stem(tree) && no_right_stem(tree))
        || command_has_error(tree, last_return, true)) {
        (*last_return) = EXIT_FAIL;
        return (EXIT_FAIL);
    }
    run_status(tree->left, env, last_return);
    if ((*last_return) == OK)
        return (run_status(tree->right, env, last_return));
    else
        return (OK);
}

int or_command(cmd_tree_t *tree, char ***env, int *last_return)
{
    if (command_has_error(tree, last_return, false)) {
        (*last_return) = EXIT_FAIL;
        return (EXIT_FAIL);
    }
    run_status(tree->left, env, last_return);
    if ((*last_return) != OK)
        return (run_status(tree->right, env, last_return));
    else
        return (OK);
}
