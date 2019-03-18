/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** remove_matches
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "matchstick.h"
#include "get_next_line.h"

int matches_check(match_t *game, char *buff, int line)
{
    int matches;

    if (my_str_isnum(buff) == 1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (-1);
    }
    matches = my_getnbr(buff);
    if (matches < 1) {
        my_putstr("Error: you have to remove at least one match\n");
        return (-1);
    }
    if (matches > (game->map[line - 1]).matches) {
        my_putstr("Error: not enough matches on this line\n");
        return (-1);
    }
    if (matches > game->max_matches) {
        error_matches(game->max_matches);
        return (-1);
    }
    return (matches);
}

int read_matches(match_t *game, int line)
{
    int matches;
    char *buff;

    my_putstr("Matches: ");
    if ((buff = get_next_line(0)) != NULL) {
        matches = matches_check(game, buff, line);
        if (matches != -1)
            game->stock_matches = matches;
    }
    else
        return (0);
    return (matches);
}

int read_line(match_t *game)
{
    char *buff;

    while (1) {
        my_putstr("Line: ");
        buff = get_next_line(0);
        if (buff == NULL)
            return (-1);
        if (my_str_isnum(buff) == 1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            continue;
        }
        game->stock_line = my_getnbr(buff);
        if (game->stock_line < 1 || game->stock_line > game->nb_lines) {
            my_putstr("Error: this line is out of range\n");
            continue;
        }
        free(buff);
        break;
    }
    return (1);
}

void print_action(match_t *game)
{
    my_putstr("Player removed ");
    my_put_nbr(game->stock_matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->stock_line);
    my_putchar('\n');
    (game->map[game->stock_line - 1]).matches =
        (game->map[game->stock_line - 1]).matches - game->stock_matches;
    (game->map[game->stock_line - 1]).spaces_r =
        (game->map[game->stock_line - 1]).spaces_r + game->stock_matches;
    game->matches = game->matches - game->stock_matches;
    print_map(game);
}

bool read_player_move_and_print_updated_board_game(match_t *game)
{
    int matches;

    my_putstr("Your turn:\n");
    while (1) {
        if (read_line(game) == -1)
            return (false);
        matches = read_matches(game, game->stock_line);
        if (matches == 0)
            return (false);
        if (matches == -1)
            continue;
        break;
    }
    print_action(game);
    return (true);
}