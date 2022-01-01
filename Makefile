
FLAGS = -Wall -Wextra -Werror
BOTH = check_args.c functions.c list_functions.c
MANDATORY = push_swap.c sort_list.c
BONUS = checker.c get_next_line.c get_next_line_bonus.c 

all: 

mandatory:
	gcc $(BOTH) $(MANDATORY) -o push_swap

bonus:
	gcc $(BOTH) $(BONUS) -o checker