/*
** EPITECH PROJECT, 2023
** navy
** File description:
** array_length
*/

#include <stdbool.h>

int arr_len(char **array)
{
    int a = 0;
    while (array[a])
        a++;
    return (a);
}

bool has_character(char *str, char check)
{
    for (int a = 0; str[a]; a++) {
        if (str[a] == check)
            return (true);
    }
    return (false);
}
