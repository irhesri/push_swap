/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:46:34 by irhesri           #+#    #+#             */
/*   Updated: 2022/03/02 14:46:37 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_list **a, int size)
{
	while (!my_issorted(*a))
	{
		if (size > 2 && (*a)->data > (*a)->next->next->data)
		{
			my_push_back(a, my_pop(a));
			my_putstr("ra", 1);
		}
		else
		{
			my_swap(a);
			my_putstr("sa", 2);
		}
	}
}

void	sort_small_list(t_list **a, t_list **b, int size)
{
	int	i;
	int	len;

	len = size;
	while (size > 3)
	{
		if ((*a)->index > (len - 3))
		{
			my_push_back(a, my_pop(a));
			my_putstr("ra", 1);
		}
		while ((*a)->index < (len - 2))
		{
			my_push(b, my_pop(a));
			my_putstr("pb", 0);
			size--;
		}
	}
	sort_3(a, size);
}
