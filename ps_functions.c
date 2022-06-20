/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:09:53 by irhesri           #+#    #+#             */
/*   Updated: 2022/02/15 14:09:55 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_push(t_stack *push, t_stack *pop)
{
	t_node	*p;

	if (!pop->size)
		return ;
	(push->size)++;
	(pop->size)--;
	p = push->head;
	push->head = pop->head;
	pop->head = pop->head->next;
	push->head->next = p;
	if (push->size == 1)
		push->tail = push->head;
}

void	my_swap(t_node *head)
{
	if (!head || !head->next)
		return ;
	head->index ^= head->next->index;
	head->next->index ^= head->index;
	head->index ^= head->next->index;
}

void	my_rotate(t_stack *stack)
{
	if (stack->size < 3)
	{
		my_swap(stack->head);
		return ;
	}
	stack->tail->next = stack->head;
	stack->head = stack->head->next; 
	stack->tail = stack->tail->next;
	stack->tail->next = NULL; 
}

void	my_rrotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 3)
	{
		my_swap(stack->head);
		return ;
	}
	tmp = stack->head;
	while (tmp->next->next)
		tmp = tmp->next;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->tail = tmp;
	tmp->next = NULL;
}
