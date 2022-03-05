#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;

	b = NULL;
	size = 0;
	a = my_check(ac, av, &size);
	 rotate (&a);
    while (a)
    {
        printf("%d\n", a->data);
        a = a->next;
    }
    
}