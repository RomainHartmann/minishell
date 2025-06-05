/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** cmd_setenv
*/

#include "macros.h"
#include "functions.h"
#include <stddef.h>
#include <stdlib.h>

static int print_error(char *msg, char *cmd)
{
    mini_printf(2, "%s: %s\n", cmd, msg);
    return 1;
}

int cmd_unsetenv(char **args, mshell_t *mshell)
{
    size_t nbr_args = len_array(args);
    env_list_t *var = NULL;

    if (nbr_args == 1)
        return print_error("Too few arguments.", args[0]);
    for (size_t i = 1; i < nbr_args; i++) {
        var = search_name(args[i], mshell);
        if (var != NULL) {
            delete_node(&mshell->env_list, var);
            update_my_env(&mshell);
        }
    }
    return DEFAULT_SUCCESS;
}
