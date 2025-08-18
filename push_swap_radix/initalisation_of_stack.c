#include "push_swap.h"

void	push_a(t_node **a, int value)
{
	t_node *new_node;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = *a;
	*a = new_node;
}