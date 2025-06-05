/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** desc
*/

#include "functions.h"

int my_put_nbr_length(int fd, int nb, int length)
{
    if (nb < 0) {
        length += 1;
        my_putchar(fd, '-');
        nb = nb * -1;
    }
    if (nb > 9) {
        length = my_put_nbr_length(fd, nb / 10, length);
        length = my_put_nbr_length(fd, nb % 10, length);
    } else {
        length += 1;
        my_putchar(fd, nb + '0');
    }
    return length;
}
