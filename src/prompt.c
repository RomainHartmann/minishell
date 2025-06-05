/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** prompt
*/

#include "functions.h"
#include "macros.h"
#include <unistd.h>

void print_prompt(void)
{
    if (isatty(0) == 1)
        mini_printf(1, "%s$> %s", COLOR_RED, COLOR_WHITE);
}
