#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//struct
typedef struct s_list
{
    int             data;
    struct s_list	*next;
} t_list;

//list
t_list  *initialise(int data);
t_list  *my_pop(t_list **list);
t_list  *my_pop_last(t_list *list);
void    my_push(t_list **list, t_list *new);
void    my_push_back(t_list **list, t_list *new);
void    my_swap(t_list **list);
int     my_issorted(t_list *list);

//new functions
int     my_check(int ac, char **av, t_list  **a);
void	my_putstr(char *s1, short check);
void    my_sort(t_list **a, t_list **b, int *lasta, int *lastb);
int     min_last(t_list *list, int *min);

/***************************************************BONUS***************************************/
char	*ft_endlsplit(char *s1, char *s2, int *size);
char	*get_next_line(int fd);
/***********************************************************************************************/

/***************************************************LIBFT***************************************/
void	ft_putstr_fd(char *s, int fd);
int     my_atoi(char *str);
int     my_strcmp(char *s1, char *s2);
/***********************************************************************************************/

#endif
