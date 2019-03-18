/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** my_str_isnum
*/

static int char_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return (1);
}

int my_str_isnum(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        if (char_is_num(str[count]) == 1)
            return (1);
        count++;
    }
    return (0);
}
