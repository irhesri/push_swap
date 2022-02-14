/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 09:41:45 by irhesri           #+#    #+#             */
/*   Updated: 2021/11/24 10:42:24 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static	char const	*my_skip(char const *s, char c, int *size, int *len)
{
	if (s)
	{
		(*len) = 0;
		while (*s == c)
		{
			(*size)--;
			s++;
		}
		while (*s != c && *s)
		{
			s++;
			(*len)++;
		}
		if (*s)
			return (s);
	}
	return (NULL);
}

static	void	my_size(int *t, char const *s, char c, int size)
{
	int	*ptr;
	int	len;
	int	i;

	if (s && t)
	{
		i = 0;
		ptr = t + 1;
		while (s)
		{
			s = my_skip(s, c, &size, &len);
			if (s)
			{
				size -= len;
				*ptr++ = len;
				i++;
			}
		}
		if (size > 0)
		{
			*ptr = size;
			i++;
		}
		*t = i;
	}
}

static	char	**my_alloc(char **str, int *t)
{
	int	i;

	if (t)
	{
		i = 0;
		str = (char **) malloc(sizeof(char *) * (t[0] + 1));
		if (str)
		{
			while (i < t[0])
			{
				str[i] = (char *) malloc(sizeof(char) * (t[i + 1] + 1));
				if (!str[i])
				{
					while (--i)
						free(str[i]);
					free(str);
					exit (0);
					break ;
				}
				i++;
			}
			return (str);
		}
	}
	return (NULL);
}

static	void	my_assignment(char **str, char const *s, char c, int *t)
{
	int	i;
	int	j;

	if (str && s)
	{
		i = 0;
		while (i < t[0])
		{
			while (*s == c)
				s++;
			j = 0;
			while (j < t[i + 1])
			{
				str[i][j] = *s;
				s++;
				j++;
			}
			str[i][j] = '\0';
			i++;
		}
		str[i] = NULL;
	}
}

char	**ft_split(char const *s, char c)
{
	int		*t;
	int		size;
	char	**str;

	if (s)
	{
		str = NULL;
		size = ft_strlen(s);
		t = (int *) malloc(sizeof(int) * (size / 2 + 2));
		my_size(t, s, c, size);
		str = my_alloc(str, t);
		if (!str)
			exit (0);
		my_assignment(str, s, c, t);
		free(t);
		return (str);
	}
	return (NULL);
}

int my_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

/*********************************new********************************/

int my_atoi(char *str)
{
	unsigned long long	n;
	int symbole;

	n = 0;
	symbole = 1;
	if (!str)
		error_case();
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
		error_case();
	return (symbole * n);
}