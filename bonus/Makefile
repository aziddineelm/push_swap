CC = cc 
FLAGS = -Wall -Wextra -Werror
SRC = array_utils_bonus.c larg_sort_bonus.c list_utils_bonus.c memory_bonus.c \
		  operations_a_bonus.c operations_b_bonus.c push_swap_bonus.c ft_split_bonus.c \
		  sorting_bonus.c stack_utils_bonus.c string_utils_bonus.c validation_bonus.c operation_bonus.c

OBJ = $(SRC:.c=.o)
NAME = checker_bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
