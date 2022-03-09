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

static int	a_b_check(char c)
{
	if (c == 'a')
		return (1);
	if (c == 'b')
		return (-1);
	return (2);
}

void	my_putstr(char *s1)
{
	static char	*s2;
	int			i;

	i = 0;
	if (!s2)
	{
		s2 = s1;
		return ;
	}
	if (s1 && s1[i] == s2[i] && ++i)
	{
		s1[i] == s2[i] && (i++);
		if (!(a_b_check(s1[i]) + a_b_check(s2[i])))
		{
			s2 = NULL;
			while (i-- > -1 && (s1[0] != 'p'))
				write(1, &s1[0], 1);
			(s1[0] != 'p') && write(1, "\n", 1);
			return ;
		}
	}
	ft_putstr(s2, 1);
	write(1, "\n", 1);
	s2 = s1;
}
