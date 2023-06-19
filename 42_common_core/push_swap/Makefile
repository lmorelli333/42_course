NAME 			= 	push_swap
SRC 			= 	main.c input_checks.c create_array.c create_array_utils.c swap.c push.c rotate.c rev_rotate.c sort.c hard_sort.c new_positions.c calculate_moves.c moves.c libft_utils.c libft_utils02.c
OBJ 			= 	$(SRC:%.c=%.o)
HEADER			=	./push_swap.h
CFLAGS 			= 	-Werror -Wall -Wextra
CC 				= 	gcc
RM				=	rm -f

all:			$(NAME)

$(NAME):	$(OBJ)
				$(CC) ${CFLAGS} -c $(SRC)
				$(CC) $(OBJ) -o $(NAME)

clean:
				${RM} ${OBJ}

fclean:			clean
					rm -f $(NAME)

re:				fclean all

.PHONY:			all clean re

