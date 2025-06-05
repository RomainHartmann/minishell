/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** contain
*/

#include <stdbool.h>
#include <stddef.h>
#include "functions.h"

bool first_contain_char(char const *str, char const c)
{
    for (size_t i = 0; str[i] && str[i] != ' '; i++)
        if (str[i] == c)
            return true;
    return false;
}

bool contain_char(char const *str, char const c)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return true;
    return false;
}

bool is_last_char(char const *str, char const c)
{
    for (int i = my_strlen(str) - 1; i != 0; i--) {
        if (str[i] == c)
            return true;
        if (str[i] != ' ')
            return false;
    }
    return false;
}
