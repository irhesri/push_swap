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

static int	my_abs(int n)
{
	if (n > 0)
		return (n + 1);
	return (n * -1);
}

static void	node_position(t_list *a, int *n_index)
{
	int	data[2];
	int	i;

	i = 0;
	data[0] = a->data;
	data[1] = a->data;
	while (a->next)
	{
		a = a->next;
		i++;
		if (a->data > data[1])
		{
			data[0] = data[1];
			n_index[0] = n_index[1];
			data[1] = a->data;
			n_index[1] = i;
		}
		else if (a->data > data[0])
		{
			data[0] = a->data;
			n_index[0] = i;
		}
	}
}

static int	max_index(t_list *a, int size)
{
	static int	b;
	int			n_index[2];

	n_index[0] = 0;
	n_index[1] = 0;
	node_position(a, n_index);
	if (n_index[1] > (size / 2 + 1))
		n_index[1] -= size;
	if (n_index[0] > (size / 2 + 1))
		n_index[0] -= size;
	if (!b && my_abs(n_index[0]) < my_abs(n_index[1]))
	{
		b = 1;
		return (n_index[0]);
	}
	b = 0;
	return (n_index[1]);
}

static void	move_up(t_list **b, int i)
{
	while (i < 0)
	{
		my_rrotate(b);
		my_putstr("rrb");
		i++;
	}
	while (i > 1)
	{
		my_rotate(b);
		my_putstr("rb");
		i--;
	}
	if (i == 1)
	{
		my_swap(b);
		my_putstr("sb");
	}
}

void	empty_b(t_list **a, t_list **b, int *size)
{
	int	i;

	i = max_index(*b, *size);
	move_up(b, i);
	if ((*a) && (*a)->next && (*a)->data > (*a)->next->data)
	{
		my_swap(a);
		my_putstr("sa");
	}
	my_push(a, b);
	my_putstr("pa");
	(*size)--;
}
