#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}
int	find_min_index(t_node **stack)
{
	t_node	*current;
	int	min;

	if (!stack || !(*stack))
		return (-1);
	current = *stack;
	min = current->index;
	while (current)
	{
		if (min > current->index)
			min = current->index;
		current = current->next;
	}
	return (min);
}

int	find_max_index(t_node **stack)
{
	t_node	*current;
	int	max;


	if (!stack || !(*stack))
		return (-1);
	max = current->index;
	current = *stack;

	while (current)
	{
		if (max < current->index)
			max = current->index;
		current = current->next;
	}
	return (max);
}

int	get_chunks(int length)
{
	
}