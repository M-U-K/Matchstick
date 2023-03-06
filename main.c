/*
** EPITECH PROJECT, 2020
** main matchstick
** File description:
** main matchstick
*/

#include "my_functions.h"

int main(int ac, char **av)
{
    data_t *data;

    if (gest_error(ac, av))
        return (84);
    data = init_data(av);
    disp_map(data);
    my_putchar('\n');
    while (data->end == 0) {
        if (disp_player_turn(data) == 84)
            return (0);
        disp_map(data);
        verif_end_player(data);
        if (data->end == 1)
            return (2);
        my_putchar('\n');
        if (game(data) == 1)
            return (1);
    }
    return (0);
}
