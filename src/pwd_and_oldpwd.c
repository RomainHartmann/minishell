/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** update_pwd
*/

#include "functions.h"
#include <stdlib.h>
#include <unistd.h>

void update_pwd(mshell_t *m, char *v)
{
    char *cwd = NULL;

    if (v == NULL)
        cwd = getcwd(NULL, 0);
    if (edit_in_list(m->env_list, "PWD", v != NULL ? v : cwd) == false)
        push_to_list(&m->env_list, "PWD", v != NULL ? v : cwd);
    update_my_env(&m);
    if (cwd != NULL)
        free(cwd);
}

void update_oldpwd(mshell_t *m, char *v)
{
    char *cwd = NULL;

    if (v == NULL)
        cwd = getcwd(NULL, 0);
    if (edit_in_list(m->env_list, "OLDPWD", v != NULL ? v : cwd) == false)
        push_to_list(&m->env_list, "OLDPWD", v != NULL ? v : cwd);
    update_my_env(&m);
    if (cwd != NULL)
        free(cwd);
}
