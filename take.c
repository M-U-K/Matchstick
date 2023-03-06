/*
** EPITECH PROJECT, 2020
** take
** File description:
** take
*/

#include "my_functions.h"

int can_take_matche(data_t *data)
{
    int cmp = 0;

    for (int i = data->width*2+1; i != 0; i --) {
        if (data->map[data->line_ia][i] == '|') {
            cmp++;
        }
    }
    if (cmp > data->matche_ia)
        return (0);
    return (1);
}

void take_matche_ia(data_t *data)
{
    data->matche_ia = 1;
}

int can_take_line(data_t *data)
{
    for (int i = 0; data->map[data->line_ia][i] != '\0'; i ++) {
        if (data->map[data->line_ia][i] == '|') {
            return (0);
        }
    }
    return (1);
}

void take_line_ia(data_t *data)
{
    data->line_ia = 0;
    while (can_take_line(data) == 1) {
        data->line_ia ++;
    }
}

void chose_matche(data_t *data)
{
    take_line_ia(data);
    take_matche_ia(data);
}
