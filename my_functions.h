/*
** EPITECH PROJECT, 2019
** my_functions.h
** File description:
** classic header
*/

#ifndef FCT_H
#define FCT_H
#include "my_structs.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int pui(int nbr, int puis);
int nbr2(int chfr, int nbr);
int find_nbr(char const *str);
int neg2(char *str, int neg, int i);
int my_getnbr(char *str);
void my_put_nbr(long nb);
void map(data_t *data, int y, int x);
void create_map(data_t *data);
data_t *init_data(char **av);
int get_line(data_t *data);
int get_matche(data_t *data);
int verif_nbr(char *str);
int gest_error(int ac, char **av);
void my_putchar(char c);
void my_putstr(char *str);
void disp_map(data_t *data);
int gest_error_line(data_t *data);
int disp_error(data_t *data);
int gest_error_matche(data_t *data);
int verif_match(data_t *data);
void rm_match(data_t *data);
void disp_player(data_t *data);
int p2(data_t *data, int i);
int disp_player_turn(data_t *data);
int can_take_matche(data_t *data);
void take_matche_ia(data_t *data);
int can_take_line(data_t *data);
void take_line_ia(data_t *data);
void chose_matche(data_t *data);
void rm_matche_ia(data_t *data);
int rdn2(data_t *data, int y, int cmp2);
int stop_random_match_line(data_t *data);
void real_ia(data_t *data);
void disp_ia_turn(data_t *data);
int player2(data_t *data, int cmp, int y);
int verif_end_player(data_t *data);
int ia2(data_t *data, int cmp, int y);
int verif_end_ia(data_t *data);
int game(data_t *data);


#endif
