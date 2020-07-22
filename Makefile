##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile
##

NAME	=	my_sokoban

CC		=	gcc -o

CFLAGS	=	-I.include/

SRC		=	src/main.c\
			src/sokoban.c\
			src/movement.c\
			src/checking_state.c\
			src/checking_map.c\
			lib/my_putstr.c\
			lib/my_str_to_tab.c\
			lib/my_strncpy.c\

OBJ		=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	gcc -I ./include $(SRC) -l ncurses -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
		rm -f $(NAME)

re: fclean all
