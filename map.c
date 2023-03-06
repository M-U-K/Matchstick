/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include "my_functions.h"

void my_put_nbr(long nb)
{
    int d = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    while ((nb / d) >= 10)
        d = d * 10;
    while (d > 0) {
        my_putchar((nb / d) % 10 + '0');
        d = d / 10;
    }
}

void map(data_t *data, int y, int x)
{
    if (x == 0 || y == 0 || x == data->width*2 || y == data->height+1)
        data->map[y][x] = '*';
    else if (x > 0 + data->width-y && x < data->width*2-data->width+y)
        data->map[y][x] = '|';
    else
        data->map[y][x] = ' ';
}

void create_map(data_t *data)
{
    int y = 0;
    int x = 0;

    for (y = 0; y != (data->height+2); y++) {
        for (x = 0; x != (data->width*2+1); x++) {
            map(data, y, x);
        }
        data->map[y][x] = '\0';
    }
}

data_t *init_data(char **av)
{
    data_t *new = malloc(sizeof(data_t));

    new->width = my_getnbr(av[1]);
    new->height = new->width;
    new->map = malloc(sizeof(char *) * (new->height+2));
    for (int i = 0; i != (new->height+2); i ++) {
        new->map[i] = malloc(sizeof(char) * (new->width*2+2));
    }
    new->str = NULL;
    new->end = 0;
    new->line_ia_save = 0;
    new->max_matche = my_getnbr(av[2]);
    create_map(new);
    new->matche_ia = 0;
    new->line_ia = 0;
    return (new);
}

int get_line(data_t *data)
{
    size_t ln = 0;

    if (getline(&data->str, &ln, stdin) == -1) {
        my_putstr("\n");
        return (1);
    }
    return (0);
}
