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
	if (a->size < 2 || my_issorted(a->head))
		exit(0);
	b = malloc(sizeof(t_stack));
	b->head = NULL;
	b->size = 0;
	list_sort(a, b, a->size);
	empty_b(a, b, b->size);
	my_putstr(NULL);
	free_stack(a);
	free_stack(b);
	return (0);
}
