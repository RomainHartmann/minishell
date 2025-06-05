/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** error
*/

#include "macros.h"
#include "functions.h"

int msg_cmd_not_found(char *cmd)
{
    mini_printf(2, "%s: Command not found.\n", cmd);
    return DEFAULT_ERROR;
}
