/*
** EPITECH PROJECT, 2021
** check above
** File description:
** x
*/

int check_above(char **str, int a, int b, int counter)
{
    int z = 0;

    while (z < counter) {
        if (str[a - 1][b] != '.')
            return 1;
        else
            a -= 1;
        z++;
    }
    return 0;
}