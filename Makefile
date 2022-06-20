NAME 		= push_swap
NAME_B 		= checker
CFLAGS 		= #-Wall -Wextra -Werror
CC 			= gcc -g -fsanitize=address
BOTH 		= list_functions.c ps_functions.c ft_split.c functions.c initialise_check.c
MANDATORY 	= push_swap.c list_sort.c empty.c
BONUS	 	= checker_bonus.c get_next_line_bonus.c
OBJ			= $(BOTH:.c=.o) $(MANDATORY:.c=.o) 
OBJ_B		= $(BONUS:.c=.o) $(BOTH:.c=.o)


all: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) $^ -o $@

bonus: $(NAME_B)

$(NAME_B) : $(OBJ_B)
	@$(CC) $^ -o $@

both: all bonus

%.o: %.c 
	@gcc $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_B)

re: fclean all

.PHONY: all clean fclean re