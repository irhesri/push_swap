
FLAGS = -Wall -Wextra -Werror
BOTH = check_initialise.c list_functions.c list_functions_2.c libft.c ft_split.c functions.c
MANDATORY = push_swap.c list_sort.c empty.c 
BONUS = checker.c get_next_line.c

all: m b

m:
	gcc $(FLAGS) $(BOTH) $(MANDATORY) -o push_swap

b:
	gcc $(FLAGS) $(BOTH) $(BONUS) -o checker
