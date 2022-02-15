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

void	my_push(t_list **list, t_list *new)
{
	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	new->next = *list;
	*list = new;
}

void	my_push_back(t_list **list, t_list *new)
{
	t_list	*lst;

	if (!new)
		return ;
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

//remove and return front 
t_list	*my_pop(t_list **list)
{
	t_list	*lst;

	lst = *list;
	if (!lst)
		return (NULL);
	*list = (*list)->next;
	lst->next = NULL;
	return (lst);
}

t_list	*my_pop_last(t_list **list)
{
	t_list	*pop;
	t_list	*lst;

	lst = *list;
	if (!lst)
		return (lst);
	if (!(lst->next))
	{
		*list = NULL;
		return (lst);
	}
	while (lst->next->next)
		lst = lst->next;
	pop = lst->next;
	lst->next = NULL;
	return (pop);
}
