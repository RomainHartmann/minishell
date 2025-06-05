/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** desc
*/

#include <stdlib.h>
#include <stdbool.h>

static bool is_delim(char const c, char const *delims)
{
    for (size_t i = 0; delims[i]; i++)
        if (c == delims[i])
            return true;
    return false;
}

static size_t count_words(char const *str, char const *delims)
{
    size_t count = 0;
    bool in_word = false;

    while (*str != '\0') {
        if (is_delim(*str, delims) == false && in_word == false) {
            in_word = true;
            count++;
        }
        if (is_delim(*str, delims) == true)
            in_word = false;
        str++;
    }
    return count;
}

static char *get_word(const char *start, size_t len)
{
    char *word = malloc(sizeof(char) * (len + 1));

    if (word == NULL)
        return NULL;
    for (size_t i = 0; i < len; i++)
        word[i] = start[i];
    word[len] = '\0';
    return word;
}

static bool set_word(char **a, char const *str, char const *start, size_t i)
{
    a[i] = get_word(start, str - start);
    if (a[i] == NULL) {
        for (int j = i - 1; j >= 0; j--)
            free(a[i]);
        free(a);
        return false;
    }
    return true;
}

static char **alloc_array(char const *str, char const *delims)
{
    char **array = NULL;

    if (str == NULL)
        return NULL;
    array = malloc(sizeof(char *) * (count_words(str, delims) + 1));
    if (array == NULL)
        return NULL;
    return array;
}

char **my_str_to_word_array(char const *str, char const *delims)
{
    char **array = alloc_array(str, delims);
    char const *start = NULL;
    size_t i = 0;

    if (array == NULL)
        return NULL;
    while (*str != '\0') {
        while (*str != '\0' && is_delim(*str, delims) == true)
            str++;
        if (*str == '\0')
            break;
        start = str;
        while (*str != '\0' && is_delim(*str, delims) == false)
            str++;
        if (set_word(array, str, start, i) == false)
            return NULL;
        i++;
    }
    array[i] = NULL;
    return array;
}
