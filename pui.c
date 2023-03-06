/*
** EPITECH PROJECT, 2020
** pui
** File description:
** pui
*/

#include "my_functions.h"

int pui(int nbr, int puis)
{
    int temp = 1;

    for (int i = 1; i < nbr; i++) {
        temp = temp * puis;
    }
    return (temp);
}

int nbr2(int chfr, int nbr)
{
    if (chfr == 0)
        nbr++;
    return (nbr);
}

int find_nbr(char const *str)
{
    int nbr = 0;
    int chfr = 0;
    int rnd = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            rnd = 1;
            nbr = nbr2(chfr, nbr);
        }
        if ((str[i] < 48 && rnd == 1) || (str[i] > 57 && rnd == 1)) {
            chfr = 1;
        }
    }
    return (nbr);
}

int neg2(char *str, int neg, int i)
{
    if (str[i - 1] == '-')
        neg++;
    return (neg);
}

int my_getnbr(char *str)
{
    int nbr = 0;
    int how_nbr = find_nbr(str);
    int neg = 0;
    int chfr = 0;
    int rnd = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57 && chfr == 0) {
            neg = neg2(str, neg, i);
            nbr = nbr + (str[i] - 48) * pui(how_nbr, 10);
            how_nbr--;
            rnd = 1;
        }
        if ((str[i] < 48 && rnd == 1) || (str[i] > 57 && rnd == 1))
            chfr = 1;
    }
    if (neg == 1)
        nbr = nbr *-1;
    return (nbr);
}
