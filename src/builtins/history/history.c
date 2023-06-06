/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** history.c
*/

#include "minishell.h"

void store_his(char *input)
{
    int fd = open(".history", O_WRONLY | O_APPEND | O_CREAT, 0644);
    struct tm *t_info;
    time_t time_n;
    char str[6];
    if (fd == ERROR)
        return;

    time(&time_n);
    t_info = localtime(&time_n);
    strftime(str, sizeof(str), "%H:%M", t_info);
    write(fd, str, strlen(str));
    write(fd, "\t", 1);
    write(fd, input, strlen(input));
    write(fd, "\n", 1);
}

int his_command(char **arg, char ***env, int *ret)
{
    char **his = str_to_word(get_file(".history"), '\n'), *str = NULL;
    int i = arr_len(his), num = 0;

    if (is_number(arg[0][1]) || is_number(arg[0][2])) {
        num = get_nbr(str_cut(arg[0], '!')), str = str_cut(arg[0], '!');
        if (num <= 0) {
            write(2, str, strlen(str)); write(2, ": Event not found.\n", 19);
            return ((*ret) = FAILURE);
        } his[num - 1] = str_cut(his[num - 1], '\t');
        his = str_to_word(his[num - 1], ' ');
    } else {
        str = str_cut(arg[0], '!');
        his[i - 1] = str_cut(his[i - 1], '\t');
        while (strncmp(str, his[i - 1], strlen(str)) != 0)
            i--, his[i - 1] = str_cut(his[i - 1], '\t');
        his = str_to_word(his[i - 1], ' ');
    }
    execute_prompt(&(his), env, ret);
    return ((*ret) = OK);
}

int my_history(char **arg, char ***env, int *ret)
{
    char **his = str_to_word(get_file(".history"), '\n');
    int i = 0;

    (void)arg, (void)env;
    while (his[i]) {
        write(1, "     ", 5);
        write(1, int_to_str(i + 1), strlen(int_to_str(i + 1)));
        write(1, "\t", 1);
        write(1, his[i], strlen(his[i]));
        write(1, "\n", 1);
        i++;
    }
    return ((*ret) = OK);
}
