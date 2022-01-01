#include "push_swap.h"

// //list size
// // size_t  my_size(t_list *lst)
// // {
// //     size_t i;

// //     i = 0;
// //     while (lst)
// //     {
// //         i++;
// //         lst = lst -> next;
// //     }
// //     return (i);
// // }

// void    my_putchar(char c)
// {
//     write(1, &c, 1);
// }

void	my_putnbr(int n)
{
	if (n > 10)
		my_putnbr(n / 10);
	n = (n % 10) + 48;
	write(1, &n, 1);
}

//print a list
void    my_print(t_list *list)
{
    while (list)
    {
        my_putnbr(list -> data);
        write(1, "\n", 1);
        list = list -> next;
    } 
}