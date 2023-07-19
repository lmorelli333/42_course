#NAME 			= 	push_swap
#NAME_BONUS		=	checker
#ARCH			=	push_swap.a
#SRC_M			= 	main.c input_checks.c create_array.c create_array_utils.c swap.c push.c rotate.c rev_rotate.c sort.c hard_sort.c new_positions.c calculate_moves.c moves.c libft_utils.c libft_utils02.c
#SRC_B			=	checker_main.c  get_next_line.c get_next_line_utils.c
#OBJ_M			=	$(SRC_M:%.c=%.o)
#OBJ_B			=	$(SRC_B:%.c=%.o)
#HEADER_M		=	./push_swap.h
#HEADER_B		=	./checker.h
#CFLAGS 			= 	-Werror -Wall -Wextra
#CC 				= 	gcc
#RM				=	rm -f

#all:			mandatory	bonus

#mandatory:		$(NAME)

#$(NAME):		$(OBJ_M)
#				$(CC) ${CFLAGS} -c $(SRC_M)
#				ar rcs $(ARCH) $(OBJ_M)
#				$(CC) $(OBJ_M) -o $(NAME)

#bonus:			$(NAME_BONUS)

#$(NAME_BONUS):	$(OBJ_B) $(ARCH)
#				$(CC) ${CFLAGS} -c  $(SRC_B)
#				$(CC) $(OBJ_B) $(ARCH) -o $(NAME_BONUS)
#clean:
#				${RM} ${OBJ_M} ${OBJ_B} 

#fclean:			clean
#				rm -f $(NAME) $(NAME_BONUS)

#re:				fclean all

#.PHONY:			all clean re

NAME         = push_swap
NAME_BONUS   = checker
ARCH         = push_swap.a

SRC_M        = main.c input_checks.c create_array.c create_array_utils.c swap.c push.c rotate.c rev_rotate.c sort.c hard_sort.c new_positions.c calculate_moves.c moves.c libft_utils.c libft_utils02.c utils.c
SRC_B        = checker_main.c get_next_line.c get_next_line_utils.c

OBJ_M        = $(SRC_M:%.c=%.o)
OBJ_B        = $(SRC_B:%.c=%.o)

HEADER_M     = ./push_swap.h
HEADER_B     = ./checker.h

CFLAGS       = -Werror -Wall -Wextra
CC           = gcc
RM           = rm -f

all: mandatory bonus

mandatory: $(NAME)

$(NAME): $(OBJ_M)
	$(CC) $(CFLAGS) -c $(SRC_M)
	ar rcs $(ARCH) $(OBJ_M)
	$(CC) $(OBJ_M) $(ARCH) -o $(NAME)

$(ARCH): $(OBJ_M)
	$(CC) $(CFLAGS) -c $(SRC_M)
	ar rcs $(ARCH) $(filter-out main.o, $(OBJ_M))
	$(CC) $(filter-out main.o, $(OBJ_M)) $(ARCH) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_B) $(ARCH)
	$(CC) $(CFLAGS) -c $(SRC_B)
	$(CC) $(OBJ_B) $(ARCH) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJ_M) $(OBJ_B) $(ARCH)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean re
