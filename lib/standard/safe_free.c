/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stdlib.h>

void safe_free(void *ptr)
{
    if (ptr)
        free(ptr);
}
