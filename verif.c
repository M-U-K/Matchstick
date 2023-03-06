/*
** EPITECH PROJECT, 2020
** verif
** File description:
** verif
*/

#include "my_functions.h"

int player2(data_t *data, int cmp, int y)
{
    for (int x = 0; data->map[y][x] != '\0'; x ++) {
        if (data->map[y][x] == '|')
            cmp++;
    }
    return (cmp);
}

int verif_end_player(data_t *data)
{
    int cmp = 0;

    for (int y = 1; y != (data->height+1); y++) {
        cmp = player2(data, cmp, y);
    }
    if (cmp == 0) {
        data->end = 1;
        my_putstr("You lost, too bad...\n");
        return (1);
    }
    return (0);
}

int ia2(data_t *data, int cmp, int y)
{
    for (int x = 0; data->map[y][x] != '\0'; x ++) {
        if (data->map[y][x] == '|')
            cmp++;
    }
    return (cmp);
}

int verif_end_ia(data_t *data)
{
    int cmp = 0;

    for (int y = 1; y != (data->height+1); y++) {
        cmp = ia2(data, cmp, y);
    }
    if (cmp == 0) {
        data->end = 1;
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (2);
    }
    return (0);
}

int game(data_t *data)
{
    if (data->end != 1) {
        disp_ia_turn(data);
        disp_map(data);
        if (verif_end_ia(data) == 2)
            return (1);
        my_putchar('\n');
    }
    return (0);
}
