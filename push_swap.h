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

//libft
void	ft_putstr_fd(char *s, int fd);
int     my_atoi(char *str);
int     my_strcmp(char *s1, char *s2);

//new functions
int     my_check(int ac, char **av, t_list  **a);

//list
t_list  *initialise(int data);
t_list  *my_pop(t_list **list);
void    my_push(t_list **list, t_list *new);
void    my_push_back(t_list **list, t_list *new);
void    my_swap(t_list **list);
void    my_rrotate(t_list **list);
int     my_issorted(t_list *list);

/***************************************************MANDATORY ONLY***************************************/
void    my_sort(t_list **a, t_list **b, int *lasta, int *lastb);
// void    my_rsort(t_list **a, int *lasta);

//new functions
void	my_putstr(char *s1, short check);
int     min_last(t_list *list, int *min);
/********************************************************************************************************/

//TO DELETE
void    my_putnbr(int n);
void    my_print(t_list *list);

#endif
