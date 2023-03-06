/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#include "my_functions.h"

int verif_match(data_t *data)
{
    int cmp = 0;

    for (int i = data->width*2+1; i != 0; i --) {
        if (data->map[data->line][i] == '|') {
            cmp++;
        }
    }
    if (cmp >= my_getnbr(data->str2))
        return (0);
    return (1);
}

void rm_match(data_t *data)
{
    for (int i = data->width*2+1; i != 0; i --) {
        if (data->map[data->line][i] == '|' && data->matche > 0) {
            data->map[data->line][i] = ' ';
            data->matche -= 1;
        }
    }
}

void disp_player(data_t *data)
{
    data->matche = my_getnbr(data->str2);
    my_putstr("Player removed ");
    my_put_nbr(data->matche);
    my_putstr(" match(es) from line ");
    my_put_nbr(data->line);
    my_putchar('\n');
    rm_match(data);
}

int p2(data_t *data, int i)
{
    if (gest_error_line(data) == 0) {
        data->line = my_getnbr(data->str);
        data->str2 = NULL;
        my_putstr("Matches: ");
        if (get_matche(data) == 1)
            return (84);
        if ((gest_error_matche(data) == 0))
            i = 1;
    }
    return (i);
}

int disp_player_turn(data_t *data)
{
    int i = 0;

    my_putstr("Your turn:\n");
    while (i == 0) {
        data->str = NULL;
        my_putstr("Line: ");
        if (get_line(data) == 1)
            return (84);
        i = p2(data, i);
        if (i == 84)
            return (84);
    }
    disp_player(data);
    return (0);
}
