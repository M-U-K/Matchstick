/*
** EPITECH PROJECT, 2020
** random
** File description:
** random
*/

#include "my_functions.h"

void rm_matche_ia(data_t *data)
{
    for (int i = data->width*2+1; i != 0; i --) {
        if (data->map[data->line_ia][i] == '|' && data->matche_ia > 0) {
            data->map[data->line_ia][i] = ' ';
            data->matche_ia -= 1;
        }
    }
}

int rdn2(data_t *data, int y, int cmp2)
{
    for (int x = data->width*2+1; x >= 0; x --) {
        if (data->map[y][x] == '|') {
            cmp2++;
            data->line_ia_save = y;
        }
    }
    return (cmp2);
}

int stop_random_match_line(data_t *data)
{
    int cmp = 0;
    int cmp2 = 0;

    for (int y = 0; y != data->height+2; y ++) {
        if (cmp2 > 0 && cmp > 0)
            return (0);
        if (cmp2 > 0) {
            cmp = cmp2;
            cmp2 = 0;
        }
        cmp2 = rdn2(data, y, cmp2);
    }
    data->match_ia_save = cmp;
    return (1);
}

void real_ia(data_t *data)
{
    data->matche_ia = 1;
    if (data->match_ia_save > 1 && data->match_ia_save <= data->max_matche) {
        data->matche_ia = data->match_ia_save - 1;
    }
    if (data->match_ia_save > 1 && data->match_ia_save == data->max_matche+1) {
        data->matche_ia = data->match_ia_save-1;
    }
}

void disp_ia_turn(data_t *data)
{
    chose_matche(data);
    if (stop_random_match_line(data) == 1){
        real_ia(data);
    }
    my_putstr("AI's turn...\nAI removed ");
    my_put_nbr(data->matche_ia);
    my_putstr(" match(es) from line ");
    my_put_nbr(data->line_ia);
    my_putchar('\n');
    rm_matche_ia(data);
}
