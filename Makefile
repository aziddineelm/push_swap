CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRC		= array_utils.c larg_sort.c list_utils.c memory.c \
		  operations_a.c operations_b.c push_swap.c ft_split.c \
		  sorting.c stack_utils.c string_utils.c validation.c
OBJ		= $(SRC:.c=.o)

NAME		= push_swap

BONUS_SRC	= bonus/array_utils_bonus.c bonus/larg_sort_bonus.c bonus/list_utils_bonus.c bonus/memory_bonus.c \
			  bonus/operations_a_bonus.c bonus/operations_b_bonus.c bonus/push_swap_bonus.c bonus/ft_split_bonus.c \
			  bonus/sorting_bonus.c bonus/stack_utils_bonus.c bonus/string_utils_bonus.c bonus/validation_bonus.c \
			  bonus/checker.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/operations_bonus.c
BONUS_OBJ	= $(BONUS_SRC:.c=.o)
BONUS_NAME	= checker

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: clean
