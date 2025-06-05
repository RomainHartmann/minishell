/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** env
*/

#include "structures.h"
#include "functions.h"
#include "macros.h"
#include <stdlib.h>
#include <stddef.h>

env_list_t *search_name(char *name, mshell_t *mshell)
{
    env_list_t *tmp = mshell->env_list;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == true)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void display_list(env_list_t *begin)
{
    env_list_t *tmp = begin;

    while (tmp != NULL) {
        mini_printf(1, "%s=%s\n", tmp->name, tmp->value);
        tmp = tmp->next;
    }
}

bool edit_in_list(env_list_t *begin, char *name, char *new_value)
{
    env_list_t *tmp = begin;

    while (tmp != NULL) {
        if (my_strcmp((tmp)->name, name) == true) {
            free(tmp->value);
            tmp->value = my_strdup(new_value);
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void delete_node(env_list_t **list, env_list_t *tmp)
{
    if (tmp->previous != NULL)
        tmp->previous->next = tmp->next;
    else
        *list = tmp->next;
    if (tmp->next != NULL)
        tmp->next->previous = tmp->previous != NULL ? tmp->previous : NULL;
    free(tmp->name);
    free(tmp->value);
    free(tmp);
}

void push_to_list(env_list_t **begin, char *name, char *value)
{
    env_list_t *e = malloc(sizeof(env_list_t));
    env_list_t *tmp = *begin;

    if (e == NULL)
        return;
    e->name = my_strdup(name);
    e->value = my_strdup(value);
    e->next = *begin;
    if (tmp != NULL)
        tmp->previous = e;
    e->previous = NULL;
    *begin = e;
}
