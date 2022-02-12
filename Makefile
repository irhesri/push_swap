
FLAGS = -Wall -Wextra -Werror
BOTH = check_initialise.c list_functions.c libft.c empty.c functions.c
MANDATORY = push_swap.c list_sort.c
BONUS = checker.c get_next_line.c get_next_line_utils.c 

all: m b

m:
	gcc $(BOTH) $(MANDATORY) -o push_swap

b:
	gcc $(FLAGS) $(BOTH) $(BONUS) -o checker