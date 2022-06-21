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

//initialise a node
t_list	*initialise(int data)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->data = data;
	lst->index = 0;
	lst->next = NULL;
	return (lst);
}

void	my_push(t_list **push, t_list **pop)
{
	t_list	*new;

	new = *pop;
	*pop = (*pop)->next;
	new->next = NULL;
	if (!new)
		return ;
	if (!*push)
	{
		*push = new;
		return ;
	}
	new->next = *push;
	*push = new;
}

void	my_push_back(t_list **list, t_list *new, int *size)
{
	t_list	*lst;

	if (!new)
		return ;
	(*size)++;
	if (!*list)
	{
		*list = new;
		return ;
	}
	lst = *list;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

void	my_rotate(t_list **list)
{
	t_list	*t;

	if (!list || !(*list) || !(*list)->next)
		return ;
	if (!(*list)->next->next)
	{
		my_swap(list);
		return ;
	}
	t = *list;
	while (t->next)
		t = t->next;
	t->next = *list;
	(*list) = (*list)->next;
	t->next->next = NULL;
}

void	my_rrotate(t_list **list)
{
	t_list	*t;

	if (!list || !(*list) || !(*list)->next)
		return ;
	if (!(*list)->next->next)
	{
		my_swap(list);
		return ;
	}
	t = *list;
	while (t->next->next)
		t = t->next;
	t->next->next = *list;
	(*list) = t->next;
	t->next = NULL;
}
