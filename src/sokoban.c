/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** Core of the game
*/

#include "../include/sokoban.h"

int find_entity(info_t *info)
{
    int i_box = 0, i_win = 0;

    for (int i = 0; info->map[i] != NULL; i++)
        for (int j = 0; info->map[i][j] != '\n'; j++) {
            if (info->map[i][j] == 'P')
                info->player[0] = (entity_t){i, j};
            if (info->map[i][j] == 'X')
                info->box[i_box++] = (entity_t){i, j};
            if (info->map[i][j] == 'O')
                info->win[i_win++] = (entity_t){i, j};
        }
        info->i_box = i_box;
        info->i_win = i_win;
}

int move_player(info_t *info, int input)
{
    switch (input) {
        case KEY_LEFT:
            move_left(info);
            break;
        case KEY_RIGHT:
            move_right(info);
            break;
        case KEY_UP:
            move_up(info);
            break;
        case KEY_DOWN:
            move_down(info);
            break;
    }
    refresh();
}

int *map_in_tab(info_t *info)
{
    int i = 0;

    while (info->map[i] != NULL) {
        mvprintw(i, 0, info->map[i]);
        i++;
    }
}

char **term_display(info_t info)
{
    int input = 0;

    initscr();
    noecho();
    curs_set(FALSE);
    map_in_tab(&info);
    keypad(stdscr, TRUE);
    refresh();
    find_entity(&info);
    while (TRUE) {
        if (input == 'q')
            break;
        input = getch();
        move_player(&info, input);
        loc_print(&info);
        mvprintw(info.player->x, info.player->y, "P");
        refresh();
        check_win(&info);
    }
    endwin();
}

void game_core(char **map, int nb_xo)
{
    entity_t *player = malloc(sizeof(*player));
    entity_t *box = malloc(sizeof(*box) * (nb_xo + 1));
    entity_t *win = malloc(sizeof(*box) * (nb_xo + 1));
    info_t info = {map, map, player, box, win};

    check_map(&info);
    term_display(info);
    free(player);
    free(box);
    free(win);
}
