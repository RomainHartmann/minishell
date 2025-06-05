/*
** EPITECH PROJECT, 2025
** MiniShell2
** File description:
** pipe
*/

#include <stddef.h>
#include "macros.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "structures.h"
#include "functions.h"

static bool errors_pipe(char *i, char **array)
{
    if (len_array(array) == 0 || is_last_char(i, '|') == true || i[0] == '|') {
        my_putstr(2, "Invalid null command.\n");
        return true;
    }
    return false;
}

static int child_process(int p[2], int cpout, char *const cmd1, mshell_t *m)
{
    int rv = DEFAULT_SUCCESS;

    close(p[0]);
    dup2(p[1], STDOUT_FILENO);
    rv = single_command(cmd1, m);
    dup2(cpout, STDOUT_FILENO);
    return rv;
}

static int parent_process(int p[2], int cpin, char *const cmd2, mshell_t *m)
{
    int rv = DEFAULT_SUCCESS;

    close(p[1]);
    dup2(p[0], STDIN_FILENO);
    rv = single_command(cmd2, m);
    dup2(cpin, STDIN_FILENO);
    close(p[0]);
    return rv;
}

static int single_pipe(char *const cmd1, char *const cmd2, mshell_t *mshell)
{
    pid_t pid = 0;
    int pipefd[2] = {};
    int dup_std[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};
    int rv = DEFAULT_SUCCESS;

    if (pipe(pipefd) == INTERNAL_ERROR)
        return DEFAULT_SUCCESS;
    pid = fork();
    if (pid < 0)
        return DEFAULT_SUCCESS;
    if (pid == 0) {
        rv = child_process(pipefd, dup_std[1], cmd1, mshell);
        exit(0);
    }
    if (pid > 0)
        rv = parent_process(pipefd, dup_std[0], cmd2, mshell);
    waitpid(pid, NULL, 0);
    return rv;
}

int my_pipe(char *input, mshell_t *mshell)
{
    char **array = my_str_to_word_array(input, "|");
    int rv = DEFAULT_SUCCESS;

    if (errors_pipe(input, array) == true) {
        free_array(array);
        return 1;
    }
    if (len_array(array) == 2)
        rv = single_pipe(array[0], array[1], mshell);
    free_array(array);
    return rv;
}
