/*
** EPITECH PROJECT, 2021
** printarray
** File description:
** x
*/

#include <stdio.h>

void my_putchar(char c);

void my_putstr(char const *str);

void my_printarr(char **str)
{
    int a = 0;

    while (str[a] != NULL) {
        my_putstr(str[a]);
        my_putchar('\n');
        a++;
    }
}