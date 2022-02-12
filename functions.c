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

int	max_value(int *size)
{
	static int i;

	if ((*size) > 100)
		i += (*size / 8);
	//else if ((*size) == 100)
		//i += ((*size) / 4);
	//else if ((*size) > 50)*/
	else
		i += ((*size) / 3);
	//i += 20;
	/*else
		i += ((*size) / 2);*/
	if (i >= (size[0] + size[1]) || *size < 25)
		return ((size[0] + size[1]) - 3);
	return (i);
}

int my_abs(int n)
{
    if (n > 0)
        return n + 1;
    return n * -1;
}