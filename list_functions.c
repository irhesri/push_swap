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

t_node	*initialise(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		exit(ft_putstr("allocation error\n", 2));
	node->data = data;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	my_push_back(t_stack *stack, t_node *new)
{
	if (!new)
		return ;
	(stack->size)++;
	if (!stack->head)
	{
		stack->head = new;
		stack->tail = new;
		return ;
	}
	stack->tail->next = new;
	stack->tail = new;
}

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
