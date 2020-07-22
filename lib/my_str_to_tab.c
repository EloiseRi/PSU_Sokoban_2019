/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** splits str into words
*/

#include "../include/sokoban.h"

int linecount(char const *map)
{
    int i = 0;
    int line = 1;

    while (map[i] != '\0') {
        if (map[i] == '\n')
            line++;
        i++;
    }
    return (line);
}

char **my_str_to_tab(char const *map, int *nb_xo)
{
    int i = 0, j = 0;
    char **tab = malloc(sizeof(char *) * (linecount(map) + 1));
    int lght = 0;

    while (map[i] != '\0') {
        if (map[i] == 'O')
            *nb_xo += 1;
        if (map[i] != '\n')
            lght++;
        if (map[i + 1] == '\n' || map[i + 1] == '\0') {
            tab[j] = malloc(sizeof(char) * (lght + 2));
            my_strncpy(tab[j], (&map[i - lght + 1]), lght);
            tab[j][lght] = '\n';
            lght = 0;
            j++;
        }
        i++;
    }
    tab[j] = NULL;
    return (tab);
}