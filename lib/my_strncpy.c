/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** Copies n char into another string
*/

#include "../include/sokoban.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int size = 0;
    int i = 0;

    n--;
    for (size = 0; src[size] != '\0'; size++);
    if (n > size)
        n = size;
    else
        size = n;
    for (i = size; i != -1; i--)
        dest[i] = src[i];
    return (dest);
}
