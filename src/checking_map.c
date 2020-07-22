/*
** EPITECH PROJECT, 2019
** checking map
** File description:
** checking_map
*/

#include "../include/sokoban.h"

int check_map(info_t *info)
{
    int p = 0;
    info->i_box = 0;
    info->i_win = 0;

    for (int i = 0; info->map[i] != NULL; i++)
        for (int j = 0; info->map[i][j] != '\n'; j++) {
            if (info->map[i][j] == 'X')
                info->i_box += 1;
            if (info->map[i][j] == 'O')
                info->i_win += 1;
            if (info->map[i][j] == 'P')
                p += 1;
        }
    if (info->i_box == 0 || info->i_win == 0 || p != 1 ||
    info->i_box != info->i_win)
        exit (84);
}

int check_case(info_t *info)
{
    for (int i = 0; info->map[i] != NULL; i++)
        for (int j = 0; info->map[i][j] != '\n'; j++) {
            if (info->map[i][j] != 'X' && info->map[i][j] != 'P'
            && info->map[i][j] != 'O' && info->map[i][j] != ' ' &&
            info->map[i][j] != '\n')
                exit (84);
        }
}
