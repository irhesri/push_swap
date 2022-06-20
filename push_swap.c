/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:24:14 by irhesri           #+#    #+#             */
/*   Updated: 2022/02/15 15:24:24 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	my_check(av, a);
	put_index(a->head, a->size);
	// if (a->size < 2 || my_issorted(a->head))
	// 	exit(0);
	b = malloc(sizeof(t_stack));
	b->head = NULL;
	b->size = 0;
	// print_stack(a->head);
	list_sort(a, b, a->size);
	print_stack(a->head);
	return 0;
	while (b->size)
		empty_b(a, b);
	while (a->head->index != 1)
	{
		my_rrotate(a);
		my_putstr("rra");
	}
	my_putstr(NULL);
	print_stack(b->head);

	// print_stack_info(a, 'A');
	// my_rrotate(a);
	// print_stack_info(a, 'A');
	// printf("---------------------------------\n");

	// print_stack_info(a, 'A');
	// my_rotate(a);
	// print_stack_info(a, 'A');
	// printf("---------------------------------\n");
	// // print_stack_info(b, 'B');
	// my_push(b, a);
	// print_stack_info(b, 'B');
	// printf("---------------------------------\n");
	// print_stack_info(b, 'B');
	// my_push(b, a);
	// print_stack_info(b, 'B');
	// printf("---------------------------------\n");
	// print_stack_info(b, 'B');
	// my_rotate(b);
	// print_stack_info(b, 'B');
	// printf("---------------------------------\n");
	// print_stack_info(a, 'A');
	// my_rotate(a);
	// print_stack_info(a, 'A');
	// printf("---------------------------------\n");
	// 	print_stack_info(a, 'A');
	// my_rotate(a);
	// print_stack_info(a, 'A');
	// printf("---------------------------------\n");
	// print_stack(a->head);

	return (0);
}
