/*
** EPITECH PROJECT, 2021
** change map
** File description:
** x
*/

void my_printarr(char **av);

void change_map(int bs, int pos_a, int pos_b, char **str)
{
    int a_counter = 0;
    int b_counter = 0;
    int a = pos_a;
    int b = pos_b;

    while (a_counter < bs) {
        while (b_counter < bs) {
            b_counter++;
            str[a][b] = 'x';
            b++;
        }
        b = b - b_counter;
        b_counter = 0;
        a++;
        a_counter++;
    }
    my_printarr(str);
}