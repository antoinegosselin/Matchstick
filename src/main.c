/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** main
*/

#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

int line_ret(void)
{
    my_putchar('\n');
    return (0);
}

int matchstick(match_t *game)
{
    int ret_function = 0;

    while (1) {
        my_putchar('\n');
        ret_function = read_player_move_and_print_updated_board_game(game);
        if (ret_function == false)
            return (line_ret());
        if (game->matches == 0) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        my_putchar('\n');
        read_ai_move_and_print_updated_board_game(game);
        if (game->matches == 0) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    match_t *game = malloc(sizeof(match_t));
    int ret_val;

    if (check_error(ac, av) == 84)
        return (84);
    srand(time(0));
    init_game(game, my_getnbr(av[1]), my_getnbr(av[2]));
    print_map(game);
    ret_val = matchstick(game);
    return (ret_val);
}