/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** binary
*/

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

char const BASE_BINARY[3] = "01";

static unsigned int count_char(unsigned int nb)
{
    int i = 1;
    while (nb > 1) {
        i++;
        nb = nb / 2;
    }
    return (i);
}

char *my_binary(int nb)
{
    char *str = malloc(sizeof(char) * (count_char(nb) + 1));
    int count = 0;
    int pos;

    for (; nb > 1; count++) {
        pos = nb % 2;
        str[count] = BASE_BINARY[pos];
        nb = nb / 2;
    }
    pos = nb % 2;
    str[count] = BASE_BINARY[pos];
    count++;
    str[count] = '\0';
    str = my_revstr(str);
    return (str);
}