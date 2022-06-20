/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:23:30 by irhesri           #+#    #+#             */
/*   Updated: 2022/02/15 15:23:32 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	node_position(t_stack *stack, int max)
{
	int		i;
	t_node	*head;

	i = 0;
	head = stack->head;
	while (head)
	{
		i++;
		if (head->index == max)
		{
			if (i > (stack->size + 1) / 2)
				return (-1);
			else
				return (1);
		}
		head = head->next;
	}
	return (0);
}

int	get_max(t_stack *a, t_stack *b, int max, int p)
{
	int	n;

	n = 0;
	while (b->head->index != max)
	{
		if (a->tail->index > max && b->head->index > a->tail->index)
		{
			my_push(a, b);
			my_putstr("pa");
			my_rotate(a);
			my_putstr("ra");
			n++;
		}
		else if (p > 0)
		{
			my_rotate(b);
			my_putstr("rb");
		}
		else
		{
			my_rrotate(b);
			my_putstr("rrb");
		}
	}
	return (n);
}

void	empty_b(t_stack *a, t_stack *b, int max)
{
	int			p;
	static int	n;

	if (max == a->tail->index)
	{
		my_rrotate(a);
		my_putstr("rra");
		n--;
		return ;
	}
	p = node_position(b, max);
	n += get_max(a, b, max, p);
	my_push(a, b);
	my_putstr("pa");
}
