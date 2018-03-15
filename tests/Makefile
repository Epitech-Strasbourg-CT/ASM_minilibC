##
## EPITECH PROJECT, 2018
## criterion
## File description:
## Makefile
##

NAME	=	tests

SRC	=	test_memcpy.c		\
		test_memmove.c		\
		test_memset.c		\
		test_rindex.c		\
		test_strcasecmp.c	\
		test_strchr.c		\
		test_strcmp.c		\
		test_strcspn.c		\
		test_strlen.c		\
		test_strncmp.c		\
		test_strpbrk.c

OBJ	=	$(SRC:.c=.o)

GCDA	=	$(SRC:.c=.gcda)

GCDO	=	$(SRC:.c=.gcno)

LDFLAGS	+=	-lcriterion -ldl  --coverage

CFLAGS	+=	-fprofile-arcs -ftest-coverage

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(GCDA) $(GCDO)

fclean: clean
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re