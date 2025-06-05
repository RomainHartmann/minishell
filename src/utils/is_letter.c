/*
** EPITECH PROJECT, 2025
** is_letter
** File description:
** desc
*/

#include <stdbool.h>

bool is_letter(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;
    return false;
}
