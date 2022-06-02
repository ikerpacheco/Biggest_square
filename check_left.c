/*
** EPITECH PROJECT, 2021
** check left
** File description:
** x
*/

int check_left(char **str, int a, int b, int counter)
{
    int x = 0;

    while (x < counter) {
        if (str[a][b - 1] != '.')
            return 1;
        else
            b -= 1;
        x++;
    }
    return 0;
}