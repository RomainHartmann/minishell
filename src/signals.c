/*
** EPITECH PROJECT, 2025
** MiniShell1
** File description:
** signals
*/

#include "macros.h"
#include "functions.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

static void ctrl_c(int i)
{
    if (i == SIGINT) {
        write(1, "\n", 1);
        print_prompt();
    }
}

bool check_error(int status)
{
    bool print = false;

    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV) {
            print = true;
            my_putstr(2, "Segmentation fault");
        }
        if (WTERMSIG(status) == SIGFPE) {
            print = true;
            my_putstr(2, "Floating exception");
        }
        if (WCOREDUMP(status)) {
            print = true;
            my_putstr(2, " (core dumped)");
        }
    }
    if (print == true)
        write(2, "\n", 1);
    return print;
}

int manage_signals(void)
{
    signal(SIGINT, ctrl_c);
    return DEFAULT_SUCCESS;
}
