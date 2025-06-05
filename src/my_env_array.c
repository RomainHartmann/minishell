/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** my_env_array
*/

#include "functions.h"
#include <stddef.h>
#include <stdlib.h>

size_t len_array(char **array)
{
    int len = 0;

    for (; array[len] != NULL; len++);
    return len;
}

void display_my_env(mshell_t *mshell)
{
    char **my_env = mshell->my_env;

    for (size_t i = 0; my_env[i] != NULL; i++) {
        my_putstr(1, my_env[i]);
        my_putchar(1, '\n');
    }
}

static int total_len(env_list_t *tmp)
{
    return sizeof(char)*(my_strlen(tmp->name) + my_strlen(tmp->value) + 2);
}

static void make_line(mshell_t **mshell, env_list_t *tmp, int i)
{
    (*mshell)->my_env[i] = malloc(total_len(tmp));
    if ((*mshell)->my_env[i] == NULL)
        return;
    my_strcpy((*mshell)->my_env[i], tmp->name);
    my_strcat((*mshell)->my_env[i], "=");
    if (tmp->value != NULL)
        my_strcat((*mshell)->my_env[i], tmp->value);
}

void update_my_env(mshell_t **mshell)
{
    env_list_t *tmp = (*mshell)->env_list;
    size_t count_var = 1;

    if (tmp == NULL)
        return;
    if ((*mshell)->my_env != NULL)
        free_array((*mshell)->my_env);
    while (tmp->next != NULL) {
        tmp = tmp->next;
        count_var++;
    }
    (*mshell)->my_env = malloc(sizeof(char *)*(count_var + 1));
    if ((*mshell)->my_env == NULL)
        return;
    for (size_t i = 0; i < count_var; i++) {
        make_line(mshell, tmp, i);
        tmp = tmp->previous;
    }
    (*mshell)->my_env[count_var] = NULL;
}
