
FLAGS = -Wall -Wextra -Werror
BOTH = check_args.c functions.c list_functions.c
MANDATORY = push_swap.c sort_list.c
BONUS = checker.c get_next_line.c get_next_line_utils.c 

all: m b

m:
	gcc $(FLAGS) $(BOTH) $(MANDATORY) -o push_swap

b:
	gcc $(FLAGS) $(BOTH) $(BONUS) -o checker