/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:25:12 by irhesri           #+#    #+#             */
/*   Updated: 2022/02/15 14:25:13 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a, int size)
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

static int	node_position(t_list *a, int max, int min)
{
	int	i;
	int	position[2];

	i = 0;
	position[0] = 0;
	while (a)
	{
		if (a->index <= max && a->index >= min)
		{
			if (!position[0])
				position[0] = i + 1;
			position[1] = i + 1;
		}
		i++;
		a = a->next;
	}
	if (!position[0])
		return (0);
	if (position[0] > (i / 2 + 1))
		return (position[1] - i - 1);
	return (position[0]);
}

static int	set_length(int size)
{
	static int	k;
	static int	x;

	k++;
	if (!x && size <= 10)
		x = 2;
	else if (!x && size < 150)
		x = 10;
	else if (!x)
		x = 30;
	return (k * x);
}

static void	push_in_b(t_list **a, t_list **b, int i)
{
	while (i > 1)
	{
		my_push_back(a, my_pop(a));
		my_putstr("ra", 1);
		i--;
	}
	while (i < 0)
	{
		my_push(a, my_pop_last(a));
		my_putstr("rra", 1);
		i++;
	}
	my_push(b, my_pop(a));
	my_putstr("pb", 0);
}

void	list_sort(t_list **a, t_list **b, int size)
{
	int	i;
	int	x;
	int	max;
	int	min;

	x = set_length(size);
	max = size / 2 + x;
	min = size / 2 - x;
	if (max >= (size - 3))
	{
		max = size - 3;
		min = 1;
	}
	i = node_position(*a, max, min);
	while (i && (*a)->next->next->next)
	{
		push_in_b(a, b, i);
		if ((*b)->index < (size / 2))
		{
			my_push_back(b, my_pop(b));
			my_putstr("rb", 1);
		}
		i = node_position(*a, max, min);
	}
}
