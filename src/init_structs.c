/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** init_structs
*/

#include "structures.h"
#include "functions.h"
#include "macros.h"
#include <stddef.h>
#include <string.h>

static int set_env_struct(env_list_t **list, char *const *envp)
{
    char *name = NULL;
    char *value = NULL;
    bool path_exist = false;

    for (size_t i = 0; envp[i] != NULL; i++) {
        name = strtok(envp[i], "=");
        value = strtok(NULL, "");
        push_to_list(list, name, value);
        if (my_strcmp("PATH", name))
            path_exist = true;
    }
    if (path_exist == false)
        push_to_list(list, "PATH", "/bin");
    return DEFAULT_SUCCESS;
}

int init_structs(mshell_t **mshell, char *const *envp)
{
    (*mshell)->env_list = NULL;
    (*mshell)->my_env = NULL;
    (*mshell)->exit = false;
    set_env_struct(&(*mshell)->env_list, envp);
    update_my_env(mshell);
    return DEFAULT_SUCCESS;
}
