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

static t_node	*initialise(int data)
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

static void	my_push_back(t_stack *stack, t_node *new)
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
