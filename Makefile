##
## EPITECH PROJECT, 2023
## B-NWP-400-NCE-4-1-fu_myftp-alexandre-kevin.de-freitas-martins
## File description:
## Makefile
##

NAME		=	myftp

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -I./include -g3

SRC			= 	main.c														   \
				src/server.c												   \
				src/create.c												   \
				src/destroy.c												   \
				src/commands_1.c											   \
				src/commands_2.c											   \
				src/commands_3.c											   \
				src/commands_4.c											   \
				src/my_read.c												   \
				src/my_write.c												   \
				src/my_frees.c												   \

OBJ			=	$(SRC:.c=.o)

all:	$(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
