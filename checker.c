/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:40:39 by irhesri           #+#    #+#             */
/*   Updated: 2022/02/15 13:40:42 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	change_both(char *str, t_list **a, t_list **b)
{
	if (!my_strcmp(str, "ss\n"))
	{
		my_swap(a);
		my_swap(b);
	}
	else if (!my_strcmp(str, "rr\n"))
	{
		my_push_back(a, my_pop(a));
		my_push_back(b, my_pop(b));
	}
	else if (!my_strcmp(str, "rrr\n"))
	{
		my_push(a, my_pop_last(a));
		my_push_back(b, my_pop_last(b));
	}
}

static	void	switch_case(char *str, t_list **a, t_list **b)
{
	if (!my_strcmp(str, "sa\n") || !my_strcmp(str, "sb\n"))
		my_swap(a);
	else if (!my_strcmp(str, "pa\n") || !my_strcmp(str, "pb\n"))
		my_push(a, my_pop(b));
	else if (!my_strcmp(str, "ra\n") || !my_strcmp(str, "rb\n"))
		my_push_back(a, my_pop(a));
	else if (!my_strcmp(str, "rra\n") || !my_strcmp(str, "rrb\n"))
		my_push(a, my_pop_last(a));
	else if (*str == 's' || *str == 'r')
		change_both(str, a, b);
	else
		exit (ft_putstr_fd("Error\n", 2));
}

static void	print_output(int b)
{
	if (b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;
	char	*str;

	if (ac == 1)
		exit (0);
	size = 0;
	b = NULL;
	a = my_check(ac, av, &size);
	str = get_next_line(0);
	if (str && !*str)
		exit (ft_putstr_fd("Error\n", 2));
	while (str)
	{
		if (str[1] == 'a' || str[2] == 'a')
			switch_case(str, &a, &b);
		else
			switch_case(str, &b, &a);
		free(str);
		str = get_next_line(0);
	}
	print_output(my_issorted(a) && !b);
	return (0);
}
