/*
** EPITECH PROJECT, 2021
** struct delcaration
** File description:
** struct
*/

#ifndef __BSQ_H__
#define __BSQ_H__

typedef struct s_bsq {
    int square;
    int position_a;
    int position_b;
    struct s_bsq *next;
} bsq_t;

#endif