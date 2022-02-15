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
		if (a -> data == new -> data)
			return (1);
		a = a -> next;
	}
	return (0);
}

t_list	*my_check(int ac, char **av, int *size)
{
	t_list	*a;
	t_list	*b;

	av++;
	if (ac == 2)
		av = ft_split(*av, ' ');
	if (!av || ac == 1)
		exit (0);
	a = NULL;
	while (*av || !a)
	{
		b = initialise(my_atoi(*av));
		if (!*av++ || duplicate_check(a, b))
			error_case();
		my_push_back(&a, b);
		(*size)++;
	}
	if (!a)
		exit(0);
	return (a);
}
