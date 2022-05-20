/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:36:43 by irhesri           #+#    #+#             */
/*   Updated: 2022/02/15 15:36:45 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;
void	print(t_list *lst);

//list functions
t_list	*initialise(int data);
void	my_push_back(t_list **list, t_list *new, int *size);
int		my_issorted(t_list *list);
void	my_push(t_list **push, t_list **pop);
void	my_swap(t_list **list);
void	my_rotate(t_list **list);
void	my_rrotate(t_list **list);

//new functions
t_list	*my_check(int ac, char **av, int *size);
void	put_index(t_list *a, int size);
void	my_putstr(char *s1);

//sort
void	sort_3(t_list **a, int size);
void	list_sort(t_list **a, t_list **b, int size);
void	empty_b(t_list **a, t_list **b, int *size);

//libft
int		ft_putstr(char *s, int fd);
int		my_atoi(char *str);
int		my_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);

//bonus
char	*get_next_line(int fd);

#endif
