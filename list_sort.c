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
			my_rotate(a);
			my_putstr("ra");
		}
		else
		{
			my_swap(a);
			my_putstr("sa");
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

static void	push_in_b(t_list **a, t_list **b, int i, int size)
{
	while (i > 1)
	{
		my_rotate(a);
		my_putstr("ra");
		i--;
	}
	while (i < 0)
	{
		my_rrotate(a);
		my_putstr("rra");
		i++;
	}
	my_push(b, a);
	my_putstr("pb");
	if ((*b)->index < (size / 2))
	{
		my_rotate(b);
		my_putstr("rb");
	}
}

void	list_sort(t_list **a, t_list **b, int size)
{
	int	i;
	int	x;
	int	max;
	int	min;

	x = 30;
	if (size <= 10)
		x = 2;
	else if (size < 150)
		x = 12;
	max = size / 2 + x;
	min = size / 2 - x;
	while ((*a)->next->next->next)
	{
		(max >= (size - 3)) && (min = 1) && (max = size - 3);
		i = node_position(*a, max, min);
		while (i && (*a)->next->next->next)
		{
			push_in_b(a, b, i, size);
			i = node_position(*a, max, min);
		}
		max += x;
		min -= x;
	}
}
