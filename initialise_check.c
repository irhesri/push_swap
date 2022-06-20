/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:24:14 by irhesri           #+#    #+#             */
/*   Updated: 2022/02/15 15:24:24 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	duplicate_check(t_node *head, int new)
{
	while (head)
	{
		if (head->data == new)
			return (1);
		head = head->next;
	}
	return (0);
}

void	my_check(char **av, t_stack *a)
{
	int		i;
	char	**list;
	t_node	*new;

	if (!a)
		exit(ft_putstr("allocation error\n", 2));
	a->head = NULL;
	a->size = 0;
	while (*++av)
	{
		list = ft_split(*av, ' ');
		if (!list[0])
			exit (ft_putstr("Error\n", 2));
		i = -1;
		while (list[++i])
		{
			new = initialise(my_atoi(list[i]));
			free(list[i]);
			if (duplicate_check(a->head, new->data))
				exit (ft_putstr("Error\n", 2));
			my_push_back(a, new);
		}
		free(list);
	}
}
