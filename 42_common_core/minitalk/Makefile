NAME_SERVER = server
NAME_CLIENT = client
HEADER = minitalk.h
SRC_SERVER =  server.c
SRC_CLIENT = client.c ft_atoi.c
OBJ_SERVER = server.o
OBJ_CLIENT = client.o ft_atoi.o
PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -Werror -Wextra -Wall

all : server client

server : $(NAME_SERVER)

client : $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJ_SERVER) $(PRINTF)
		$(CC) $(CFLAGS) -c $(SRC_SERVER)
		$(CC) $(OBJ_SERVER) $(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJ_CLIENT) $(PRINTF)
		$(CC) $(CFLAGS) -c $(SRC_CLIENT)
		$(CC) $(OBJ_CLIENT) $(PRINTF) -o $(NAME_CLIENT)

$(PRINTF):
		make -C $(PRINTF_PATH)

clean :
		${RM} ${OBJ_SERVER} ${OBJ_CLIENT}
		make clean -C $(PRINTF_PATH)

fclean : clean
		rm -f $(NAME_SERVER) ${NAME_CLIENT}
		rm -f $(PRINTF)

re : fclean all

.PHONY:			all clean re