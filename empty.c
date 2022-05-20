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

static int	node_position(t_list *lst, int n, short b)
{
	static int	len;
	int			i;
	if (!len)
		len = n;
	if (!b)
	{
		len--;
		return (0);
	}
	i = 0;
	while (lst)
	{
		i++;
		if (lst->index == n)
		{
			len--;
			if (i > (len + 1) / 2)
				return (-1);
			else
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}

static int	get_last(t_list *lst)
{
	if (!lst)
		return (-1);
	while (lst->next)
		lst = lst->next;
	return (lst->index);
}
void	empty_b(t_list **a, t_list **b, int *size)
{
	int			p;
	static int	n;
	static int	last;
	
	p = node_position(*b, *size, 1);
	if (!p)
	{
		my_rrotate(a);
		my_putstr("rra");
		n--;
		(*size)--;
		if (n)
			last = get_last(*a);
		return ;
	}
	while ((*b)->index != (*size))
	{
		if (!n || ((*b)->index > last))
		{
			last = (*b)->index;
			my_push(a, b);
			my_putstr("pa");
			my_rotate(a);
			my_putstr("ra");
			n++;
			node_position(*a, n, 0);
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
	my_push(a, b);
	my_putstr("pa");
	(*size)--;
}