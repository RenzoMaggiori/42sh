/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** helper_tree_enclosing
*/

#include "minishell.h"

int get_enclosing_index(char *str, int index, char *op)
{
    if (str[index] == op[0]) {
        print_error(TOO_PAR_R);
        return (ERROR);
    }
    while (index >= 0) {
        if (str[index] == op[1]) {
            print_error(TOO_PAR_L);
            return (ERROR);
        }
        if (str[index] == op[0])
            return (index);
        index--;
    }
    return (ERROR);
}
