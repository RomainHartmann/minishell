/*
** EPITECH PROJECT, 2025
** MiniShell2
** File description:
** command
*/

#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "macros.h"
#include "array.h"
#include "functions.h"

size_t exec_path(char *cmd, char **args, int child_pid, mshell_t *mshell)
{
    if (child_pid != 0)
        return DEFAULT_ERROR;
    if (execve(cmd, args, mshell->my_env) == -1)
        return free_input(args, args[0][0] != '.' ? cmd : NULL);
    return DEFAULT_SUCCESS;
}

static int check_path_env(char *input, mshell_t *mshell)
{
    char **p = get_path_array(mshell);
    char **args = my_str_to_word_array(input, " \t");
    int return_value = DEFAULT_SUCCESS;
    char *path = NULL;

    for (size_t i = 0; p != NULL && p[i]; i++) {
        path = set_path(args[0], p[i]);
        return_value = srch_cmd(args, mshell, path, p[i + 1] == NULL);
        if (is_valid_path(path) == true) {
            free(path);
            break;
        }
        free(path);
    }
    if (p == NULL)
        msg_cmd_not_found(args[0]);
    free_array(args);
    free_array(p);
    return p == NULL ? 1 : return_value;
}

static bool check_builtin_exist(char *input)
{
    char **args = my_str_to_word_array(input, " \t");
    bool builtinExist = false;

    for (size_t i = 0; ARRAY_BUILTIN[i].cmd != NULL; i++) {
        if (my_strcmp(args[0], ARRAY_BUILTIN[i].cmd)) {
            builtinExist = true;
            break;
        }
    }
    free_input(args, NULL);
    return builtinExist;
}

static int start_builtin(char *input, mshell_t *mshell)
{
    char **args = my_str_to_word_array(input, " \t");
    int return_value = false;

    for (size_t i = 0; ARRAY_BUILTIN[i].cmd != NULL; i++) {
        if (my_strcmp(args[0], ARRAY_BUILTIN[i].cmd)) {
            return_value = ARRAY_BUILTIN[i].function(args, mshell);
            break;
        }
    }
    free_input(args, NULL);
    return return_value;
}

static int check_file(char *input, mshell_t *mshell)
{
    struct stat statbuf = {0};
    char **args = my_str_to_word_array(input, " \t");
    char *path = args[0];
    int child_pid = 0;
    int status = 0;

    if (stat(path, &statbuf) == 0) {
        child_pid = fork();
        exec_path(path, args, child_pid, mshell);
        waitpid(child_pid, &status, 0);
    } else {
        msg_cmd_not_found(args[0]);
        free_input(args, NULL);
        return 1;
    }
    free_input(args, NULL);
    if (check_error(status))
        return status;
    return WIFEXITED(status) ? WEXITSTATUS(status) : DEFAULT_SUCCESS;
}

int single_command(char *input, mshell_t *mshell)
{
    size_t rv = DEFAULT_SUCCESS;

    if (first_contain_char(input, '/') == true)
        rv = check_file(input, mshell);
    else {
        if (check_builtin_exist(input) == true)
            rv = start_builtin(input, mshell);
        else
            rv = check_path_env(input, mshell);
    }
    return rv;
}
