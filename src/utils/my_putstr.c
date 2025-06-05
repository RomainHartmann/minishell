/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** desc
*/

#include "functions.h"
#include <unistd.h>

void my_putchar(int fd, char c)
{
    write(fd, &c, 1);
}

int my_putstr(int fd, char const *str)
{
    int len = my_strlen(str);

    write(fd, str, len);
    return len;
}
