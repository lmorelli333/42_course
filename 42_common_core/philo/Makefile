# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 10:43:21 by lmorelli          #+#    #+#              #
#    Updated: 2023/07/22 21:15:27 by lmorelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC	=	initialize.c philo.c utils.c actions.c

HEADER			=	./philo.h

OBJ				= 	$(SRC:%.c=%.o)

CC				=	gcc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror


all:			$(NAME)

$(NAME):		$(OBJ) 
				$(CC) ${CFLAGS} -c $(SRC)
				$(CC) $(OBJ) -o $(NAME)

clean:
				${RM} ${OBJ}

fclean:			clean
				rm -f $(NAME)
				
re:				fclean all

.PHONY:			all clean re

