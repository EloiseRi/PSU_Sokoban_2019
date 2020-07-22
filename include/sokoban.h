/*
** EPITECH PROJECT, 2019
** my_soko
** File description:
** my_soko
*/

#ifndef SOKOBAN
#define SOKOBAN

#define IS_NOTOK(c) (c != '#' && c != 'X' && c != 'O' && c != '\n' && c != ' ')

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <stdbool.h>

/* Structures */
typedef struct entity_s {
    int x;
    int y;
} entity_t;

typedef struct info_s {
    char **map;
    char **original;
    entity_t *player;
    entity_t *box;
    entity_t *win;
    unsigned int i_box;
    unsigned int i_win;
} info_t;

/* Prototypes */

/* Library */
int my_putstr(char const *map);
char *my_strncpy(char *dest, char const *src, int n);
int linecount(char const *map);
char **my_str_to_tab(char const *map, int *nb_xo);

/* main.c */
int main(int ac, char **av);
int help(void);
char *open_file(char const *filepath, int ac);

/* sokoban.c */
void game_core(char **map, int nb_xo);
char **term_display(info_t map_info);
int *map_in_tab(info_t *info);
int find_entity(info_t *map_info);
int move_player(info_t *map_info, int input);

/* movement.c */
void move_up(info_t *info);
void move_down(info_t *info);
void move_left(info_t *info);
void move_right(info_t *info);
void loc_print(info_t *info);

/* checking_state.c */
int checking_map(char *map);
bool check_box(int x, int y, info_t *info);
bool check_wall(char **map, int x, int y);
int check_win(info_t *info);
int check_lose(info_t *info);

/* checking_map.c */
int check_map(info_t *info);
int check_case(info_t *info);

#endif /* !SOKOBAN */
