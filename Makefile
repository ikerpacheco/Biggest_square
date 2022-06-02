##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makes file
##

SRC	=	my_putchar.c \
		my_putstr.c \
		read_map.c \
		bsq.c \
		my_getnbr.c \
		my_strlen.c \
		my_printarr.c \
		change_map.c \
		check_above.c \
		check_left.c \
		shortener.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all