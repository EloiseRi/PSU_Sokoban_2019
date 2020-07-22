/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../include/sokoban.h"

char *open_file(char const *filepath, int ac)
{
    int fd = open(filepath, O_RDONLY);

    struct stat size;
    char *buffer_map;
    if (fd == -1) {
        my_putstr("Can't open file\n");
        exit (84);
    }
    if (stat(filepath, &size) == -1) exit (84);
    if (size.st_size <= 1) exit (84);
    buffer_map = malloc(sizeof(char *) * (size.st_size));
    read(fd, buffer_map, size.st_size);
    buffer_map[size.st_size] = '\0';
    close(fd);
    return (buffer_map);
}

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map, containing\
    '#' for walls, \n");
    my_putstr("\t'P' for the players, 'X' for boxes and 'O'\
    for storage locations.\n");
}

int main(int ac, char **av)
{
    char *buffer_map;
    char **map;
    int nb_xo = 0;

    if (ac != 2) exit (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return 0;
    }
    buffer_map = open_file(av[1], ac);
    map = my_str_to_tab(buffer_map, &nb_xo);

    game_core(map, nb_xo);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    free(buffer_map);
}