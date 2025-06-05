/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** is_alpha
*/

#include <stdbool.h>

bool is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;
    if (c >= '0' && c <= '9')
        return true;
    return false;
}
