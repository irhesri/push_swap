NAME = push_swap
NAME_B = checker
FLAGS = -Wall -Wextra -Werror
BOTH = check_initialise.c list_functions.c list_functions_2.c libft.c ft_split.c functions.c
MANDATORY = push_swap.c list_sort.c empty.c 
BONUS = checker_bonus.c get_next_line_bonus.c

all: $(NAME)

$(NAME): $(BOTH:.c=.o) $(MANDATORY:.c=.o) 

$(NAME_B): $(BONUS:.c=.o) $(BOTH:.c=.o)
	gcc $(BONUS:.c=.o) $(BOTH:.c=.o) -o $@

bonus:$(NAME_B)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re