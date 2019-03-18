/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#ifndef  READ_SIZE
#define  READ_SIZE 50
#endif  //READ_SIZE

#ifndef GETNEXTLINE_H
#define GETNEXTLINE_H

char *get_next_line(int fd);
char *my_get_strndup(char *str, int n);
char *my_get_strncat(char *dest, char *str, int n);

#endif //GETNEXTLINE_H