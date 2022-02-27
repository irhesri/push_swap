/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_initialise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:43:28 by irhesri           #+#    #+#             */
/*   Updated: 2022/02/15 13:43:30 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	duplicate_check(t_list *a, t_list *new)
{
	while (a)
	{
		if (a->data == new->data)
			return (1);
		a = a->next;
	}
	return (0);
}

t_list	*my_check(int ac, char **av, int *size)
{
	t_list	*a;
	t_list	*b;
	char	**list;

	av++;
	a = NULL;
	while (ac-- && *av)
	{
		list = ft_split(*av, ' ');
		if (!list)
			exit (0);
		while (*list || !a)
		{
			b = initialise(my_atoi(*list));
			if (!*list++ || duplicate_check(a, b))
				exit (ft_putstr_fd("Error\n", 2));
			my_push_back(&a, b);
			(*size)++;
		}
		av++;
	}
	if (!a)
		exit(0);
	return (a);
}
