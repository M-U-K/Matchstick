/*
** EPITECH PROJECT, 2020
** error.c
** File description:
** error.c
*/

#include "my_functions.h"

void disp_map(data_t *data)
{
    for (int y = 0; y != (data->height+2); y++) {
        my_putstr(data->map[y]);
        my_putchar('\n');
    }
}

int gest_error_line(data_t *data)
{
    if (data->str == NULL) {
        return (1);
    }
    for (int i = 0; data->str[i+1] != '\0'; i ++) {
        if (data->str[i] < 48 || data->str[i] > 57) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        }
    }
    if (data->str[0] == '\n') {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (my_getnbr(data->str) > data->height || my_getnbr(data->str) <= 0) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}

int disp_error(data_t *data)
{
    if (my_getnbr(data->str2) > data->max_matche) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(data->max_matche);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (my_getnbr(data->str2) > data->width*2) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    if (my_getnbr(data->str2) <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    if (verif_match(data)) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}

int gest_error_matche(data_t *data)
{
    if (data->str2 == NULL) {
        return (1);
    }
    for (int i = 0; data->str2[i+1] != '\0'; i ++) {
        if (data->str[i] < 48 || data->str[i] > 57) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        }
    }
    if (data->str2[0] == '\n') {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (disp_error(data) == 1)
        return (1);
    return (0);
}
