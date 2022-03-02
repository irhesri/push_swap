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
	if (size == 1 || my_issorted(a))
		exit(0);
	put_index(a, size);
	if (size > 10)
	{
		while (a)
			list_sort(&a, &b, size);
	}
	else
		sort_small_list(&a, &b, size);
	while (b)
		empty_b(&a, &b, &size);
	if (a && a->next && a->data > a->next->data)
	{
		my_swap(&a);
		my_putstr("sa", 2);
	}
	my_putstr(NULL, 0);
}
