#include "push_swap.h"

void	push(t_node **stack, int value)
{
	t_node *new_node;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = *stack;
	*stack = new_node;
}