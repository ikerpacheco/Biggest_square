/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** Get map from file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_strlen(char const *str);

int my_getnbr(char const *str);

int find_bsq(char **str, int counter);

int shortener(char **str, int a, int *b);

int error_handling(char **str, int size, char *buffer)
{
    int a = 1;
    int b = 0;

    if (size <= 1)
        return 84;
    while (str[a] != NULL) {
        if (shortener(str, a, &b) == 84)
            return 84;
        b = 0;
        a++;
    }
    return 0;
}

int str_to_array(char *buffer)
{
    int size = my_getnbr(buffer) + 1;
    char **str = malloc(size * sizeof(char *));
    int i = 0;
    int counter = 1;
    int j = 0;
    while (buffer[i] != '\n')
        i++;
    i++;
    while (buffer[i] != '\0') {
        str[j] = &buffer[i];
        while (buffer[i] != '\n')
            i++;
        buffer[i] = '\0';
        j++;
        i++;
    }
    if (error_handling(str, size, buffer) == 84)
        return 84;
    find_bsq(str, counter);
    return 0;
}

int char_detector(char *buffer)
{
    int x = 0;

    if ((buffer[x] > '9') || (buffer[x] < '0'))
        return 84;
    return 0;
}

int get_map(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat buff;
    char *buffer;
    int i = 0;

    stat(filepath, &buff);
    buffer = malloc(buff.st_size + 1);
    read(fd, buffer, buff.st_size);

    if (char_detector(buffer) == 84)
        return 84;
    if (my_getnbr(buffer) >= 500)
        return 84;
    while (buffer[i] != '\n')
        i++;
    if (i >= 500)
        return 84;
    if (str_to_array(buffer) == 84)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (get_map(av[1]) == 84)
        return 84;
    return 0;
}