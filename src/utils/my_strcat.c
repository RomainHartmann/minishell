/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** desc
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int i2 = 0;

    while (dest[i] != '\0') {
        i = i + 1;
    }
    while (src[i2] != '\0') {
        dest[i] = src[i2];
        i = i + 1;
        i2 = i2 + 1;
    }
    dest[i] = '\0';
    return (dest);
}
