/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** ia2
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "matchstick.h"
#include "get_next_line.h"

void remove_matches(match_t *game, int nb_line, int line)
{
    int matches;

    if (nb_line % 2 == 1) {
        matches = game->map[line].matches;
        matches = (matches > game->max_matches) ? 1 : matches;
    } else {
        matches = game->map[line].matches - 1;
        matches = (matches > game->max_matches) ? 1 : matches;
    }
    game->map[line].matches -= matches;
    game->map[line].spaces_r += matches;
    game->matches -= matches;
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line + 1);
}

int end_only_one(match_t *game)
{
    int line;
    int nb_line;

    for (int i = 0; i < game->nb_lines; i++) {
        if (game->map[i].matches == 1)
            nb_line++;
        if (game->map[i].matches > 1)
            line = i;
    }
    remove_matches(game, nb_line, line);
    return (0);
}

int one_line_ai(match_t *game)
{
    int matches;
    int line;

    for (line = 0; line < game->nb_lines; line++) {
        if (game->map[line].matches > 0) {
            matches = game->map[line].matches - 1;
            matches = (matches > game->max_matches) ? 1 : matches;
            matches = (game->map[line].matches == 1) ? 1 : matches;
            break;
        }
    }
    game->map[line].matches -= matches;
    game->map[line].spaces_r += matches;
    game->matches -= matches;
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line + 1);
    return (0);
}

int only_one(match_t *game)
{
    int one_line = 0;
    int more_line = 0;

    for (int i = 0; i < game->nb_lines; i++) {
        if (game->map[i].matches == 1)
            one_line++;
        if (game->map[i].matches > 1)
            more_line++;
    }
    if (one_line == 0 && more_line == 1)
        return (one_line_ai(game));
    if (more_line == 0) {
        no_even_nim(game);
        return (0);
    }
    if (more_line == 1)
        return (end_only_one(game));
    return (1);
}