/*
** EPITECH PROJECT, 2019
** movement
** File description:
** handle move
*/

#include "../include/sokoban.h"

void move_up(info_t *info)
{
    if (!check_wall(info->map, info->player->x - 1, info->player->y)
    && !check_box(info->player->x - 1, info->player->y, info)){
        mvprintw(info->player->x, info->player->y, " ");
        info->player->x--;
    } else if (!check_wall(info->map, info->player->x - 1, info->player->y)
    && !check_wall(info->map, info->player->x - 2, info->player->y)) {
        for (int i = 0; i != info->i_box; i++)
            if ((info->player->y == info->box[i].y &&
                info->player->x - 1 == info->box[i].x) &&
                (info->map[info->box[i].x - 1][info->box[i].y] != 'X')) {
                info->map[info->box[i].x - 1][info->box[i].y] = 'X';
                info->map[info->player->x - 1][info->player->y] = ' ';
                mvprintw(info->player->x, info->player->y, " ");
                info->player->x--;
                info->box[i].x--;
            }
    }
}

void move_down(info_t *info)
{
    if (!check_wall(info->map, info->player->x + 1, info->player->y)
    && !check_box(info->player->x + 1, info->player->y, info)){
        mvprintw(info->player->x, info->player->y, " ");
        info->player->x++;
    } else if (!check_wall(info->map, info->player->x + 1, info->player->y)
    && !check_wall(info->map, info->player->x + 2, info->player->y)) {
        for (int i = 0; i != info->i_box; i++)
            if ((info->player->y == info->box[i].y &&
                info->player->x + 1 == info->box[i].x) &&
                (info->map[info->box[i].x + 1][info->box[i].y] != 'X')) {
                info->map[info->box[i].x + 1][info->box[i].y] = 'X';
                info->map[info->player->x + 1][info->player->y] = ' ';
                mvprintw(info->player->x, info->player->y, " ");
                info->player->x++;
                info->box[i].x++;
            }
    }
}

void move_left(info_t *info)
{
    if (!check_wall(info->map, info->player->x, info->player->y - 1)
    && !check_box(info->player->x, info->player->y - 1, info)){
        mvprintw(info->player->x, info->player->y, " ");
        info->player->y--;
    } else if (!check_wall(info->map, info->player->x, info->player->y - 1)
    && !check_wall(info->map, info->player->x, info->player->y - 2)) {
        for (int i = 0; i != info->i_box; i++)
            if ((info->player->y - 1 == info->box[i].y &&
                info->player->x == info->box[i].x) &&
                (info->map[info->box[i].x][info->box[i].y - 1] != 'X')) {
                info->map[info->box[i].x][info->box[i].y - 1] = 'X';
                info->map[info->player->x][info->player->y - 1] = ' ';
                mvprintw(info->player->x, info->player->y, " ");
                info->player->y--;
                info->box[i].y--;
            }
    }
}

void move_right(info_t *info)
{
    if (!check_wall(info->map, info->player->x, info->player->y + 1)
    && !check_box(info->player->x, info->player->y + 1, info)){
        mvprintw(info->player->x, info->player->y, " ");
        info->player->y++;
    } else if (!check_wall(info->map, info->player->x, info->player->y + 1)
    && !check_wall(info->map, info->player->x, info->player->y + 2)) {
        for (int i = 0; i != info->i_box; i++)
            if ((info->player->y + 1 == info->box[i].y) &&
                (info->player->x == info->box[i].x)
                && (info->map[info->box[i].x][info->box[i].y + 1] != 'X')) {
                info->map[info->box[i].x][info->box[i].y + 1] = 'X';
                info->map[info->player->x][info->player->y + 1] = ' ';
                mvprintw(info->player->x, info->player->y, " ");
                info->player->y++;
                info->box[i].y++;
            }
    }
}

void loc_print(info_t *info)
{
    for (int i = 0; i != info->i_win; i++) {
            info->map[info->win[i].x][info->win[i].y] = 'O';
            mvprintw(info->win[i].x, info->win[i].y, "O");
    }
    for (int j = 0; j != info->i_box; j++) {
            info->map[info->box[j].x][info->box[j].y] = 'X';
            mvprintw(info->box[j].x, info->box[j].y, "X");
    }
}