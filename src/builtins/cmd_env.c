/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** cmd_env
*/

#include "macros.h"
#include "functions.h"

int cmd_env(char **args, mshell_t *mshell)
{
    (void)args;
    display_my_env(mshell);
    return DEFAULT_SUCCESS;
}
