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

int	ft_putstr(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
	return (1);
}

int	my_atoi(char *str)
{
	unsigned long long	n;
	int					symbole;

	n = 0;
	symbole = 1;
	if (!str)
		exit (ft_putstr("Error\n", 2));
	if (*str == '-')
		symbole = -1;
	if ((*str == '+' || *str == '-') && *(str + 1))
		str++;
	while (*str > 47 && *str < 58 && (n < 2147483648))
	{
		n = n * 10 + *str - 48;
		str++;
	}
	if (*str || (n >= 2147483648 && symbole == 1)
		|| (n > 2147483648 && symbole == -1))
		exit (ft_putstr("Error\n", 2));
	return (symbole * n);
}
