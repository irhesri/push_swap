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

void	sort_3(t_stack *a, int size)
{
	while (!my_issorted(a->head))
	{
		if (size > 2 && a->head->index > a->tail->index)
		{
			my_rotate(a);
			my_putstr("ra");
		}
		else
		{
			my_swap(a->head);
			my_putstr("sa");
		}
	}
}

static int	node_position(t_stack *stack, int max, int min)
{
	int		i;
	int		pos;
	t_node	*head;

	i = 0;
	head = stack->head;
	pos = 0;
	while (head)
	{
		if (head->index <= max && head->index >= min)
		{
			if (!pos)
			{
				if ((i + 1) <= (stack->size / 2))
					return (i + 1);
			}
			pos = i;
		}
		i++;
		head = head->next;
	}
	if (!pos)
		return (pos);
	return (pos - i);
}

static void	push_in_b(t_stack *a, t_stack *b, int i, int size)
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
	if (b->head->index < (size / 2))
	{
		my_rotate(b);
		my_putstr("rb");
	}
}

void	list_sort(t_stack *a, t_stack *b, int size)
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
	max = size / 2;
	min = max;
	while (a->size > 3)
	{
		max += x;
		min -= x;
		(max >= (size - 3)) && (min = 1) && (max = size - 3);
		i = node_position(a, max, min);
		while (i && a->size > 3)
		{
			push_in_b(a, b, i, size);
			i = node_position(a, max, min);
		}
	}
	sort_3(a, 3);
}
