#include "push_swap.h"

void	print_stack(t_node *head)
{
	while (head)
	{
		printf("%d - ", head->index);
		head = head->next;
	}
	printf("\n");
}

void	print_stack_info(t_stack *stack, char c)
{
	printf("%c: \n", c);
	printf("size = %d\n", stack->size);
	printf("head = %d\n", stack->head->index);
	printf("tail = %d\n", stack->tail->index);
	print_stack(stack->head);
}