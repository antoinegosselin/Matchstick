/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick
*/

#include <stdbool.h>

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

//structs
typedef struct line_s
{
    int spaces_l;
    int matches;
    int spaces_r;
} line_t;
typedef struct match_s
{
    int matches;
    int nb_lines;
    int max_matches;
    int stars;
    int stock_line;
    int stock_matches;
    line_t *map;
} match_t;

//map
void print_map(match_t *game);
int get_last_line(int nb_line);

//init
int get_nb_matches(int nb_lines);
int check_error(int ac, char **av);
void init_map(match_t *game, int nb_lines);
void init_game(match_t *game, int nb_lines, int max_matches);

//move
int ai_line(match_t *game);
int read_line(match_t *game);
int ai_matches(match_t *game, int line);
int read_matches(match_t *game, int line);
void read_ai_move_and_print_updated_board_game(match_t *game);
bool read_player_move_and_print_updated_board_game(match_t *game);

int matchstick(match_t *game);
void error_matches(int matches);
int line_check(match_t *game, char *buff);
char *my_binary(int nb);
void no_even_nim(match_t *game);
int one_line_ai(match_t *game);
int only_one(match_t *game);
int end_only_one(match_t *game);
void remove_matches(match_t *game, int nb_line, int line);

#endif //MATCHSTICK_H
