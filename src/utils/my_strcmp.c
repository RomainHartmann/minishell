/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** my_strcmp
*/

#include "functions.h"
#include <stdbool.h>

bool my_strcmp(char const *s1, char const *s2)
{
    int const count_s1 = my_strlen(s1);
    int const count_s2 = my_strlen(s2);

    if (count_s1 != count_s2)
        return false;
    for (size_t i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}
