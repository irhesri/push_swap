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
	t_list	*a;
	t_list	*b;
	int		size;

	b = NULL;
	size = 0;
	a = my_check(ac, av, &size);
	if (!a || size == 1 || my_issorted(a))
		exit(0);
	put_index(a, size);
	if (size > 3)
		list_sort(&a, &b, size);
	sort_3(&a, 3);
	size -= 3;
	while (size)
		empty_b(&a, &b, &size);
	while (a->index != 1)
	{
		my_rrotate(&a);
		my_putstr("rra");
	}
	my_putstr(NULL);
	return (0);
}
