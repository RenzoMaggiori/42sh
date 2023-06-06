/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** tree
*/

#include "minishell.h"
cmd_tree_t *tree_fill(cmd_tree_t *tree, char *arg);

bool parenthesis_is_valid(char *arg, int split, int *par)
{
    return (((*par) = get_enclosing_index(arg, split, "()")) != ERROR);
}

char **command_split(char *arg, char **type)
{
    int new_split = get_split_index(arg, type), par = 0;
    char **new = malloc(sizeof(char *) * 2);
    char *split_str = NULL;

    if (!new || new_split == ERROR
        || ((arg[new_split] == ')' || arg[new_split] == '(')
        && !parenthesis_is_valid(arg, new_split, &par))) {
        return (NULL);
    }
    new[0] = nstr_dup(new_split, arg);
    split_str = from_str_dup(new_split, arg);
    new[1] = from_str_dup(find_cut_index(split_str), split_str);
    free(split_str);
    return (new);
}

cmd_tree_t *tree_create(char *arg)
{
    cmd_tree_t *tree = malloc(sizeof(cmd_tree_t));

    if (!tree || !arg)
        return (NULL);
    tree->argument = arg;
    tree->left = NULL;
    tree->right = NULL;
    tree_fill(tree, arg);
    return (tree);
}

cmd_tree_t *tree_fill(cmd_tree_t *tree, char *arg)
{
    char *type = NULL;
    char **split = command_split(arg, &type);

    if (!split || !type)
        return (tree);
    tree->argument = type;
    tree->left = tree_create(split[0]);
    tree->right = tree_create(split[1]);
    return (tree);
}
