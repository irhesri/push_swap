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

int	my_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	instruction(char *c, t_list **a, t_list **b)
{
	if (c[0] == 's')
		my_swap(a);
	else if (c[0] == 'p' && c[1] != 'p')
		my_push(a, b);
	else if (c[0] == 'r' && c[2] == '\0')
		my_rotate(a);
	else if (c[0] == 'r' && c[1] == 'r')
		my_rrotate(a);
	else
		exit (ft_putstr("Error\n", 2));
}

static	int	execute(char *str, t_list **a, t_list **b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((str[i + 1] == 'a' || str[i + 1] == 'b') && !str[i + 2])
		{
			instruction(str, a, b);
			return (1);
		}
		i++;
	}
	if (str[0] == str[1] && (!str[2] || !my_strcmp(str, "rrr")))
	{
		instruction(str, a, b);
		instruction(str, b, a);
		return (1);
	}
	exit (ft_putstr("Error\n", 2));
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
	while (str)
	{
		((str[1] == 'a' || str[2] == 'a') && execute(str, &a, &b))
			|| execute(str, &b, &a);
		free(str);
		str = get_next_line(0);
	}
	(my_issorted(a) && !b && !ft_putstr("OK\n", 1)) || ft_putstr("KO\n", 1);
	return (0);
}
