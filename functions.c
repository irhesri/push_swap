#include "push_swap.h"

static  int is_rotate(char *str)
{
    if (!(my_strcmp(str, "ra")))
        return (1);
    if (!(my_strcmp(str, "rb")))
        return (-1);   
    return (2); 
}

static  int is_swap(char *str)
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
	static char *s2;

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
    while (*s2)
        write(1, s2++, 1);
    write(1, "\n", 1);
	s2 = s1;
}

/************************************LIBFT********************************/
//put string
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
//convert string to integer
int my_atoi(char *str)
{
    unsigned int	n;
	int symbole;

	n = 0;
	symbole = 1;

	if (*str == '-')
		symbole = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str > 47 && *str < 58)
	{
		n = n * 10 + *str - 48;
		str++;
	}
	return (symbole * n);
}


