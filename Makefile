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
				src/my_read.c												   \
				src/my_write.c												   \
				src/my_frees.c												   \
				src/client.c												   \
				src/selects.c												   \
				src/commands/cdup.c										   	   \
				src/commands/cwd.c											   \
				src/commands/dele.c										   	   \
				src/commands/help.c										   	   \
				src/commands/list.c										   	   \
				src/commands/noop.c										   	   \
				src/commands/not_logged.c									   \
				src/commands/pass.c										   	   \
				src/commands/pasv.c										   	   \
				src/commands/port.c										   	   \
				src/commands/pwd.c											   \
				src/commands/quit.c										   	   \
				src/commands/retr.c										   	   \
				src/commands/stor.c										   	   \
				src/commands/user.c										   	   \

OBJ			=	$(SRC:.c=.o)

all:	$(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
