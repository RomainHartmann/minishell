/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** search_cmds
*/

#include "functions.h"
#include "macros.h"
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

char **get_path_array(mshell_t *mshell)
{
    env_list_t *tmp = mshell->env_list;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, "PATH") == true && tmp->value)
            return my_str_to_word_array(tmp->value, ":");
        tmp = tmp->next;
    }
    return NULL;
}

char *set_path(char *cmd, char *prefix_path)
{
    char *path = NULL;
    int len = my_strlen(prefix_path) + 1 + my_strlen(cmd);

    path = malloc(sizeof(char) * (len + 1));
    if (path == NULL)
        return NULL;
    my_strcpy(path, prefix_path);
    if (prefix_path[my_strlen(prefix_path) - 1] != '/')
        my_strcat(path, "/");
    my_strcat(path, cmd);
    return path;
}

bool is_valid_path(char *path)
{
    struct stat statbuf = {0};

    if (stat(path, &statbuf) == 0)
        return true;
    return false;
}

int srch_cmd(char **args, mshell_t *mshell, char *path, bool show_error)
{
    int child_pid = 0;
    int status = 0;

    if (is_valid_path(path) == true) {
        child_pid = fork();
        exec_path(path, args, child_pid, mshell);
        waitpid(child_pid, &status, 0);
    } else {
        if (show_error == true)
            msg_cmd_not_found(args[0]);
        return 1;
    }
    if (check_error(status))
        return status;
    return WIFEXITED(status) ? WEXITSTATUS(status) : DEFAULT_SUCCESS;
}
