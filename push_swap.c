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

static void	my_check(char **av, t_stack *a)
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		max;

	if (ac == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	my_check(av, a);
	put_index(a->head, a->size);
	if (a->size < 2 || my_issorted(a->head))
		exit(0);
	b = malloc(sizeof(t_stack));
	b->head = NULL;
	b->size = 0;
	list_sort(a, b, a->size);
	max = b->size;
	while (b->size)
		empty_b(a, b, max--);
	while (a->head->index != 1)
	{
		my_rrotate(a);
		my_putstr("rra");
	}
	my_putstr(NULL);
	return (0);
}
