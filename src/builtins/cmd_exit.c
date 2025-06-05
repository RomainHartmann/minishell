/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** cmd_exit
*/

#include "macros.h"
#include "functions.h"

int cmd_exit(char **args, mshell_t *mshell)
{
    (void)args;
    (void)mshell;
    mshell->exit = true;
    return DEFAULT_SUCCESS;
}
