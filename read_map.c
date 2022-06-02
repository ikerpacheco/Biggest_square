/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** Check character
*/

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);

void my_putstr(char const *str);

void my_printarr(char **str);

void change_map(int bs, int pos_a, int pos_b, char **str);

int check_above(char **str, int a, int b, int counter);

int check_left(char **str, int a, int b, int counter);

bsq_t *init_bsq(int square, int position_a, int position_b)
{
    bsq_t *bsq = malloc(sizeof(bsq_t));
    if (bsq == NULL)
        return NULL;
    bsq->square = square;
    bsq->position_a = position_a;
    bsq->position_b = position_b;
    bsq->next = NULL;
    return bsq;
}

void create_new_bsq(int square, int position_a, int position_b, bsq_t *bsq)
{
    bsq_t *tmp = bsq;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = init_bsq(square, position_a, position_b);
}

int checker(char **str, int a, int b, int counter)
{
    int above = 0;
    int left = 0;

    if (str[a][b + 1] == '\0' || str[a + 1] == NULL)
        return counter;

    if (str[a + 1][b + 1] == '.') {
        a += 1;
        b += 1;
        above = check_above(str, a, b, counter);
        left = check_left(str, a, b, counter);
        if (left == 0 && above == 0) {
            counter++;
            left = 0;
            above = 0;
            counter = checker(str, a, b, counter);
        }
    }
    return counter;
}

void check_bsq(bsq_t *bsq, char **str)
{
    bsq_t *tmp = bsq;
    int bs = 0;
    int pos_a = 0;
    int pos_b = 0;

    while (tmp != NULL) {
        if (bs < tmp->square) {
            bs = tmp->square;
            pos_a = tmp->position_a;
            pos_b = tmp->position_b;
        }
        tmp = tmp->next;
    }
    change_map(bs, pos_a, pos_b, str);
}

int find_bsq(char **str, int counter)
{
    bsq_t *bsq = init_bsq(0, 0, 0);
    int a = 0;
    int b = 0;
    int surroundings = 0;

    while (str[a] != NULL) {
        while (str[a][b] != '\0') {
            if (str[a][b] == '.') {
                surroundings = checker(str, a, b, counter);
                create_new_bsq(surroundings, a, b, bsq);
                counter = 1;
            }
            b++;
        }
        b = 0;
        a++;
    }
    check_bsq(bsq, str);
    return surroundings;
}