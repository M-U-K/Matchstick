/*
** EPITECH PROJECT, 2020
** matche
** File description:
** matche
*/

#include "my_functions.h"

int get_matche(data_t *data)
{
    size_t ln = 0;

    if (getline(&data->str2, &ln, stdin) == -1) {
        my_putstr("\n");
        return (1);
    }
    return (0);
}

int verif_nbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i ++) {
        if (str[i] < 48 || str[i] > 57)
            return (1);
    }
    return (0);
}

int gest_error(int ac, char **av)
{
    if (ac != 3)
        return (1);
    if (verif_nbr(av[1]))
        return (1);
    if (verif_nbr(av[1]))
        return (1);
    if (my_getnbr(av[1]) <= 0)
        return (1);
    if (my_getnbr(av[2]) <= 0)
        return (1);
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}
