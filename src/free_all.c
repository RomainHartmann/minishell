/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** free_all
*/

#include "macros.h"
#include "structures.h"
#include "functions.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void free_array(char **args)
{
    if (args == NULL)
        return;
    for (size_t i = 0; args[i] != NULL; i++) {
        free(args[i]);
    }
    free(args);
}

int free_input(char **args, char *alloc_path)
{
    if (alloc_path != NULL)
        free(alloc_path);
    free_array(args);
    return DEFAULT_ERROR;
}

void free_list(env_list_t *list)
{
    env_list_t *tmp = list;
    env_list_t *prev = list;

    while (tmp != NULL) {
        free(tmp->name);
        free(tmp->value);
        prev = tmp;
        tmp = tmp->next;
        free(prev);
    }
}

void free_end(mshell_t *mshell)
{
    free_array(mshell->my_env);
    free_list(mshell->env_list);
    free(mshell);
}
