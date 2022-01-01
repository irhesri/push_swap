/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 08:11:49 by irhesri           #+#    #+#             */
/*   Updated: 2021/12/18 08:12:30 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_next_line(char *str, int fd)
{
	char	*s;
	ssize_t	len;
	int		size;

	size = 0;
	s = NULL;
	s = ft_endlsplit(s, str, &size);
	if (s[size - 1] == '\n')
		return (s);
	len = 1;
	while (len > 0)
	{
		len = read(fd, str, 100);
		if (len > 0)
		{
			str[len] = '\0';
			s = ft_endlsplit(s, str, &size);
			if (s[size - 1] == '\n')
				return (s);
		}
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*s;

	if (!str)
	{
		str = (char *) malloc(sizeof(char) * 101);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	s = read_next_line(str, fd);
	if (*s == '\0')
	{
		free (str);
		free (s);
		str = NULL;
		return (NULL);
	}
	return (s);
}
