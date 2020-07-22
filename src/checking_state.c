/*
** EPITECH PROJECT, 2019
** checking
** File description:
** checking
*/

#include "../include/sokoban.h"

bool check_wall(char **map, int x, int y)
{
    if (map[x][y] == '#')
        return (TRUE);
    return FALSE;
}

bool check_box(int x, int y, info_t *info)
{
    if (info->map[x][y] == 'X')
            return TRUE;
    return FALSE;
}

/*int check_lose(info_t *info)
{
    for (int i = 0; i != info->i_box; i++)
        if ()
            mvprintw(10, 0, "Lose");
}*/

int check_win(info_t *info)
{
    int count = 0;

    for (int i = 0; i != info->i_win; i++)
        for (int j = 0; j != info->i_box; j++) {
            if (info->map[info->win[i].x][info->win[i].y]
            == info->map[info->box[j].x][info->box[j].y])
                count++;
        }
    if (count == info->i_win * 2) {
        endwin();
        exit (1);
    }
}