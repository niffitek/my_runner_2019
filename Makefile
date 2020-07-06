##
## EPITECH PROJECT, 2019
## Hunter
## File description:
## Makefile
##

SRC     =	src2/player.c \
            src2/main.c \
            src2/create.c \
            src2/event.c \
            src2/background.c \
            src2/map.c \
            src2/text.c \
            src2/game.c

TESTS	=	tests/test_my_runner.c $(SRC)

OBJ	=	$(SRC:.c=.o)

OBJ_TESTS =	$(TESTS:.c=.o)

NAME    =	my_runner

TEST_NAME =	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio

tests_run:	$(OBJ_TESTS)
		gcc -o $(TEST_NAME) $(OBJ_TESTS) -lcriterion --coverage
		./unit_tests

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
