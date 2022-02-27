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

static int	node_position(t_list *a, int max, int min)
{
	int	i;
	int	position;

	i = 0;
	position = 0;
	while (a)
	{
		if (a->index <= max && a->index >= min)
		{
			position = i + 1;
			break ;
		}
		i++;
		a = a->next;
	}
	if (!position)
		return (0);
	return (position);
}

static int	set_length(int size)
{
	static int	k;
	static int	x;

	k++;
	if (!x && size < 150)
		x = 12;
	else if (!x)
		x = 30;
	if (size > 150)
		return (k * x);
	return (k * x);
}

void	list_sort(t_list **a, t_list **b, int size)
{
	int	i;
	int	x;

	x = set_length(size);
	i = node_position(*a, (size / 2 + x), (size / 2 - x));
	while (i)
	{
		while (i >= 2)
		{
			my_push_back(a, my_pop(a));
			my_putstr("ra", 1);
			i--;
		}
		my_push(b, my_pop(a));
		my_putstr("pb", 0);
		if ((*b)->index < (size / 2))
		{
			my_push_back(b, my_pop(b));
			my_putstr("rb", 1);
		}
		i = node_position(*a, (size / 2 + x), (size / 2 - x));
	}
}

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

void	sort_5(t_list **a, t_list **b, int size)
{
	int	i;

	while (size > 3)
	{
		i = node_position(*a, 2, 1);
		if ((i - 1) > (size / 2))
			i -= (size + 1);
		while (i < 0)
		{
			my_push(a, my_pop_last(a));
			my_putstr("rra", 0);
			i++;
		}
		while (i > 1)
		{
			my_push_back(a, my_pop(a));
			my_putstr("ra", 1);
			i--;
		}
		my_push(b, my_pop(a));
		my_putstr("pb", 0);
		size--;
	}
	sort_3(a, size);
}
