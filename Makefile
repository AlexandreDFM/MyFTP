##
## EPITECH PROJECT, 2023
## B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
## File description:
## Makefile
##

NAME		=	myftp

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -I./include -g3

SRC			= 	main.c														   \
				src/server.c												   \

OBJ			=	$(SRC:.c=.o)

all:	$(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
