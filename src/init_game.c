/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** init_map
*/

#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

int get_nb_matches(int nb_lines)
{
    int matches = 1;
    int total = 0;

    for (int i = 0; i < nb_lines; i++) {
        total = total + matches;
        matches = matches + 2;
    }
    return (total);
}

void init_map(match_t *game, int nb_lines)
{
    int matches = 1;
    int spaces = (get_last_line(nb_lines) - 1) / 2;

    for (int i = 0; i < nb_lines; i++) {
        (game->map[i]).matches = matches;
        (game->map[i]).spaces_l = spaces;
        (game->map[i]).spaces_r = spaces;
        matches = matches + 2;
        spaces--;
    }
}

void init_game(match_t *game, int nb_lines, int max_matches)
{
    game->nb_lines = nb_lines;
    game->matches = get_nb_matches(nb_lines);
    game->max_matches = max_matches;
    game->stars = get_last_line(nb_lines) + 2;
    game->map = malloc(sizeof(line_t) * nb_lines);
    init_map(game, nb_lines);
}