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

// static int	node_position(t_list *a, int max, int min, int len)
// {
// 	int	i;
// 	int	position;

// 	i = 0;
// 	position = 0;
// 	while (a)
// 	{
// 		if (a->index <= max && a->index >= min)
// 		{
// 			position = i + 1;
// 			if (i + 1 < (len / 2))
// 				break ;
// 			else
// 				position = len - position + 1;
// 		}
// 		i++;
// 		a = a->next;
// 	}
// 	if (!position)
// 		return (0);
// 	return (position);
// }
static int	node_position(t_list *a, int max, int min, int len)
{
	int	i;
	int	first;
	int	last;

	i = 0;
	first = 0;
	last = 0;
	while (a)
	{
		if (a->index <= max && a->index >= min)
		{
			if (!first)
				first = i + 1;
			last = i + 1;
		}
		i++;
		a = a->next;
	}
	if (first > (i / 2))
		return (i - last + 1);
	if (!first)
		return (0);
	return (first);
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
	return (k * x);
}

static void	move_up(t_list **a, int i)
{
	while (i >= 2)
	{
		my_push_back(a, my_pop(a));
		my_putstr("ra", 1);
		i--;
	}
	while (i < 0)
	{
		my_push(a, my_pop_last(a));
		my_putstr("rra", 0);
		i++;
	}
}

void	list_sort(t_list **a, t_list **b, int size)
{
	int	i;
	int	x;

	x = set_length(size);
	i = node_position(*a, (size / 2 + x), (size / 2 - x), size);
	while (i)
	{
		move_up(a, i);
		my_push(b, my_pop(a));
		my_putstr("pb", 0);
		if ((*b)->index < (size / 2))
		{
			my_push_back(b, my_pop(b));
			my_putstr("rb", 1);
		}
		i = node_position(*a, (size / 2 + x), (size / 2 - x), size);
	}
}
