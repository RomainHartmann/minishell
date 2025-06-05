/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** cmd_cd
*/

#include "macros.h"
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>

static int print_error(char *msg, char *path, char *oldpwd)
{
    mini_printf(2, "%s: %s\n", path, msg);
    free(oldpwd);
    return 1;
}

static int error_chdir(char **args, char *oldpwd)
{
    if (errno == ENOTDIR)
        return print_error("Not a directory.", args[1], oldpwd);
    if (errno == ENOENT)
        return print_error("No such file or directory.", args[1], oldpwd);
    if (errno == EACCES)
        return print_error("Permission denied.", args[1], oldpwd);
    return DEFAULT_SUCCESS;
}

static int simple_cd(char *HOME, char **args, mshell_t *mshell, char *oldpwd)
{
    if (HOME == NULL)
        return print_error("No home directory.", args[0], oldpwd);
    if (chdir(HOME) == -1)
        return error_chdir(args, oldpwd);
    update_oldpwd(mshell, oldpwd);
    update_pwd(mshell, NULL);
    free(oldpwd);
    return DEFAULT_SUCCESS;
}

static int tilde_cd(char *HOME, char **args, mshell_t *mshell, char *oldpwd)
{
    if (HOME == NULL) {
        my_putstr(2, "No $home variable set.\n");
        free(oldpwd);
        return 1;
    }
    if (chdir(HOME) == -1)
        return error_chdir(args, oldpwd);
    update_oldpwd(mshell, oldpwd);
    update_pwd(mshell, NULL);
    free(oldpwd);
    return DEFAULT_SUCCESS;
}

static int minus_cd(char **args, mshell_t *mshell, char *oldpwd)
{
    env_list_t *OLDPWD = search_name("OLDPWD", mshell);

    if (OLDPWD == NULL)
        return print_error("No such file or directory.", "", oldpwd);
    if (chdir(OLDPWD->value) == -1)
        return error_chdir(args, oldpwd);
    update_oldpwd(mshell, oldpwd);
    update_pwd(mshell, NULL);
    free(oldpwd);
    return DEFAULT_SUCCESS;
}

int cmd_cd(char **args, mshell_t *mshell)
{
    int nbr_args = len_array(args);
    env_list_t *path_env = search_name("HOME", mshell);
    char *HOME = path_env != NULL ? path_env->value : NULL;
    char *oldpwd = getcwd(NULL, 0);

    if (nbr_args == 1)
        return simple_cd(HOME, args, mshell, oldpwd);
    if (nbr_args > 2)
        return print_error("Too many arguments.", args[0], oldpwd);
    if (my_strcmp(args[1], "~"))
        return tilde_cd(HOME, args, mshell, oldpwd);
    if (my_strcmp(args[1], "-"))
        return minus_cd(args, mshell, oldpwd);
    if (chdir(args[1]) == -1)
        return error_chdir(args, oldpwd);
    update_oldpwd(mshell, oldpwd);
    update_pwd(mshell, NULL);
    free(oldpwd);
    return DEFAULT_SUCCESS;
}
