/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** ia
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "matchstick.h"
#include "get_next_line.h"

int nim_sum(match_t *game)
{
    int k = 0;

    for (int i = 0; i < game->nb_lines; i++)
        k = k ^ game->map[i].matches;
    return (k);
}

void no_even_nim(match_t *game)
{
    int line;
    int matches = 1;

    line = (rand() % game->nb_lines);
    while (game->map[line].matches < 1)
        line = (rand() % game->nb_lines);
    game->map[line].matches -= matches;
    game->map[line].spaces_r += matches;
    game->matches -= matches;
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line + 1);
}

int loop(match_t *game, int line)
{
    int matches;

    for (matches = 1; ((matches <= game->map[line].matches) &&
        (matches <= game->max_matches)); matches++) {
        game->map[line].matches -= matches;
        if (nim_sum(game) == 0) {
            game->map[line].spaces_r += matches;
            game->matches -= matches;
            my_put_nbr(matches);
            my_putstr(" match(es) from line ");
            my_put_nbr(line + 1);
            return (0);
        }
        game->map[line].matches += matches;
    }
    return (1);
}

void test(match_t *game)
{
    int line;
    int ret_val;

    if (only_one(game) == 0)
        return;
    for (line = 0; line < game->nb_lines; line++) {
        ret_val = loop(game, line);
        if (ret_val == 0)
            return;
    }
    no_even_nim(game);
}

void read_ai_move_and_print_updated_board_game(match_t *game)
{
    my_putstr("AI's turn...\n");
    my_putstr("AI removed ");
    test(game);
    my_putchar('\n');
    print_map(game);
}