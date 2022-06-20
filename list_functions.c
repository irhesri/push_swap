/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:15:46 by irhesri           #+#    #+#             */
/*   Updated: 2022/02/15 14:15:50 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if list is sorted
int	my_issorted(t_node *head)
{
	while (head && head->next)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

void	put_index(t_node *head, int size)
{
	int		i;
	t_node	*min;
	t_node	*check;

	i = 0;
	while (i < size)
	{
		min = head;
		check = head->next;
		while (check)
		{
			if ((!check->index && min->data > check->data)
				|| (min->index))
				min = check;
			check = check->next;
		}
		min->index = ++i;
	}
}
