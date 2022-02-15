/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:51:01 by irhesri           #+#    #+#             */
/*   Updated: 2022/02/15 13:51:04 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_rotate(char *str)
{
	if (!(my_strcmp(str, "ra")))
		return (1);
	if (!(my_strcmp(str, "rb")))
		return (-1);
	return (2);
}

static int	is_swap(char *str)
{
	if (!(my_strcmp(str, "sa")))
		return (1);
	if (!(my_strcmp(str, "sb")))
		return (-1);
	return (2);
}

//prints s2 and store s1 in s2
void	my_putstr(char *s1, short check)
{
	static char	*s2;

	if (!s2)
	{
		s2 = s1;
		return ;
	}
	if (check == 1 && !(is_rotate(s1) + is_rotate(s2)))
	{	
		s1 = NULL;
		s2 = "rr";
	}
	else if (check == 2 && !(is_swap(s1) + is_swap(s2)))
	{	
		s1 = NULL;
		s2 = "ss";
	}
	ft_putstr_fd(s2, 1);
	write(1, "\n", 1);
	s2 = s1;
}

void	error_case(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
}
