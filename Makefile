##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/print_map.c \
		src/get_next_line.c \
		src/init_game.c \
		src/remove_matches.c \
		src/ia.c \
		src/ia2.c \
		src/error.c \
		src/binary.c

NAME	=	matchstick

OBJ	=	$(SRC:.c=.o)

LIB_PATH	=	./lib/my/

LIB_NAME	=	my

TEST_PATH 	= 	./tests/

CFLAGS	=	-W -Wall -I include/

all:	$(NAME) clean

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) $(OBJ) -L$(LIB_PATH) -l$(LIB_NAME) $(CFLAGS)

clean:
	make clean -C ./lib/my/
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIB_PATH)libmy.a
	rm -f unit_test*

re:	fclean all

tests_run: 
	