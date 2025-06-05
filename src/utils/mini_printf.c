/*
** EPITECH PROJECT, 2025
** miniprintf
** File description:
** desc
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

static int display(int fd, const char *format, va_list list, const int i)
{
    int length = 0;

    if (format[i + 1] == 'd') {
        length += my_put_nbr_length(fd, va_arg(list, int), 0);
    }
    if (format[i + 1] == 'i') {
        length += my_put_nbr_length(fd, va_arg(list, int), 0);
    }
    if (format[i + 1] == 's') {
        length += my_putstr(fd, va_arg(list, char *));
    }
    if (format[i + 1] == 'c') {
        my_putchar(fd, va_arg(list, int));
        length += 1;
    }
    if (format[i + 1] == '%') {
        my_putchar(fd, '%');
        length += 1;
    }
    return length;
}

static bool condition_replace(const char *format, const int i)
{
    if (format[i] == '%') {
        if (is_letter(format[i + 1]) == true || format[i + 1] == '%') {
            return true;
        }
    }
    return false;
}

int mini_printf(int fd, const char *format, ...)
{
    va_list list;
    int length = 0;

    va_start(list, format);
    for (size_t i = 0; format[i] != '\0'; i++) {
        if (condition_replace(format, i) == true) {
            length += display(fd, format, list, i);
            i++;
        } else {
            my_putchar(fd, format[i]);
            length++;
        }
    }
    va_end(list);
    return length;
}
