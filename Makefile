CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRC		= array_utils.c larg_sort.c list_utils.c memory.c \
		  operations_a.c operations_b.c push_swap.c ft_split.c \
		  sorting.c stack_utils.c string_utils.c validation.c
OBJ		= $(SRC:.c=.o)

NAME	= push_swap

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS) :
	cd bonus && make
	mv checker ../

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
