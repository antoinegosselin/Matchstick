/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** error
*/

#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

void error_matches(int matches)
{
    my_putstr("Error: you cannot remove more than ");
    my_put_nbr(matches);
    my_putstr(" matches per turn\n");
}

int check_error(int ac, char **av)
{
    int nb1;
    int nb2;

    if (ac != 3)
        return (84);
    for (int i = 1; i < 3; i++) {
        if (my_str_isnum(av[i]) == 1)
            return (84);
    }
    nb1 = my_getnbr(av[1]);
    nb2 = my_getnbr(av[2]);
    if (nb1 < 2 || nb1 > 99)
        return (84);
    if (nb2 < 1)
        return (84);
    return (0);
}