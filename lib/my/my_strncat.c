/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** my_strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int count;

    for (count = 0 ; count < nb && src[count] != '\0' ; count++)
        dest[dest_len + count] = src[count];
    dest[dest_len + count] = '\0';

    return dest;
}
