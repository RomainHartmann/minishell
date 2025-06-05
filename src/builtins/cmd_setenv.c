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

static int print_error(char *msg)
{
    mini_printf(2, "setenv: %s\n", msg);
    return 1;
}

static bool check_errors(char **args)
{
    char *str = args[1];

    if (is_letter(str[0]) == false && str[0] != '_') {
        print_error("Variable name must begin with a letter.");
        return true;
    }
    for (size_t i = 0; str[i] != '\0'; i++)
        if (is_alpha(str[i]) == false && str[i] != '_' && str[i] != '.') {
            print_error("Variable name must contain alphanumeric characters.");
            return true;
        }
    return false;
}

static int no_args(mshell_t *mshell)
{
    display_my_env(mshell);
    return DEFAULT_SUCCESS;
}

int cmd_setenv(char **args, mshell_t *mshell)
{
    int nbr_args = len_array(args);

    if (nbr_args == 1)
        return no_args(mshell);
    if (nbr_args > 3)
        return print_error("Too many arguments.");
    if (check_errors(args) == true)
        return 1;
    if (edit_in_list(mshell->env_list, args[1], args[2]) == false)
        push_to_list(&mshell->env_list, args[1], args[2]);
    update_my_env(&mshell);
    return DEFAULT_SUCCESS;
}
