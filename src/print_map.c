/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** print_map
*/

#include "my.h"
#include "matchstick.h"

int get_last_line(int nb_line)
{
    int nb_stick = 1;

    for (int i = 1; i < nb_line; i++)
        nb_stick = nb_stick + 2;
    return (nb_stick);
}

void put_stars(match_t *game, int option)
{
    if (option == 1) {
        for (int i = 0; i < game->stars; i++)
            my_putchar('*');
        my_putchar('\n');
        my_putchar('*');
    }
    else if (option == 3) {
        for (int j = 0; j < (game->stars - 1); j++)
            my_putchar('*');
        my_putchar('\n');
    } else
        my_putstr("*\n*");
}

void print_map(match_t *game)
{
    put_stars(game, 1);
    for (int j = 0; j < game->nb_lines; j++) {
        for (int l = 0; l < (game->map[j]).spaces_l; l++)
            my_putchar(' ');
        for (int m = 0; m < (game->map[j]).matches; m++)
            my_putchar('|');
        for (int n = 0; n < (game->map[j]).spaces_r; n++)
            my_putchar(' ');
        put_stars(game, 2);
    }
    put_stars(game, 3);
}