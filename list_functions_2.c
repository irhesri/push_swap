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

void	my_swap(t_list **list)
{
	t_list	*lst;

	lst = *list;
	if (!lst || !lst -> next)
		return ;
	*list = (*list)-> next;
	lst -> next = (*list)-> next;
	(*list)-> next = lst;
}

//check if list is sorted
int	my_issorted(t_list *lst)
{
	while (lst && lst -> next)
	{
		if (lst -> data > lst -> next -> data)
			return (0);
		lst = lst -> next;
	}
	return (1);
}

void	put_index(t_list *a, int size)
{
	int		i;
	t_list	*min;
	t_list	*check;

	i = 0;
	while (i < size)
	{
		min = a;
		check = a -> next;
		while (check)
		{
			if ((!check -> index && min -> data > check -> data)
				|| (min -> index))
				min = check;
			check = check -> next;
		}
		min -> index = ++i;
	}
}
