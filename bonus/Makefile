CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRC		= array_utils_bonus.c larg_sort_bonus.c list_utils_bonus.c memory_bonus.c \
		  operations_a_bonus.c operations_b_bonus.c push_swap_bonus.c ft_split_bonus.c \
		  sorting_bonus.c stack_utils_bonus.c string_utils_bonus.c validation_bonus.c \
		  checker.c get_next_line_bonus.c get_next_line_utils_bonus.c operations_bonus.c
OBJ		= $(SRC:.c=.o)

NAME	= checker

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
