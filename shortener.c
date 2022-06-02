/*
** EPITECH PROJECT, 2021
** shortener
** File description:
** shortener
*/

int shortener(char **str, int a, int *b)
{
    while (str[a][(*b)] != '\0') {
        if (!(str[a][(*b)] == '.' || str[a][(*b)] == 'o'))
            return 84;
        (*b)++;
    }
    return 0;
}