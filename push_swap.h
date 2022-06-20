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

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

//list functions
t_node	*initialise(int data);
void	my_push_back(t_stack *list, t_node *new);
int		my_issorted(t_node *head);
void	my_push(t_stack *push, t_stack *pop);
void	my_swap(t_node *head);
void	my_rotate(t_stack *stack);
void	my_rrotate(t_stack *stack);
void	free_stack(t_stack *stack);

//new functions
void	put_index(t_node *head, int size);
void	my_putstr(char *s1);
void	my_check(char **av, t_stack *a);

//sort
void	list_sort(t_stack *a, t_stack *b, int size);
void	empty_b(t_stack *a, t_stack *b, int max);

//libft
int		ft_putstr(char *s, int fd);
int		my_atoi(char *str);
char	**ft_split(char const *s, char c);

//bonus
char	*get_next_line(int fd);

void	print_stack(t_node *head);

#endif
