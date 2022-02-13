#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
    int             data;
    int             index;
    struct s_list  *next;
} t_list;

void    put_index(t_list *a, int size);
void    sort_3(t_list **a, int size);
int my_abs(int n);
//list
t_list  *initialise(int data);
t_list  *my_pop(t_list **list);
t_list  *my_pop_last(t_list **list);
void    my_push(t_list **list, t_list *new);
void    my_push_back(t_list **list, t_list *new);
void    my_swap(t_list **list);
int     my_issorted(t_list *list);

//new functions
t_list  *my_check(int ac, char **av, int *size);
void	my_putstr(char *s1, short check);
int	    max_value(int *size);
void    list_sort(t_list **a, t_list **b, int size);
//void    push_in_b(t_list **a, t_list **b, t_info *info_a, t_info *info_b);

/***************************************************LIBFT***************************************/
void	ft_putstr_fd(char *s, int fd);
int     my_atoi(char *str);
int     my_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
size_t  ft_strlen(const char *str);
/***********************************************************************************************/

/***************************************************BONUS***************************************/
char	*ft_endlsplit(char *s1, char *s2, int *size);
char	*get_next_line(int fd);
/***********************************************************************************************/
void    empty_b(t_list **a, t_list **b, int *size);

#endif