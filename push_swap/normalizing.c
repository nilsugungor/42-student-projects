#include "push_swap.h"

int	ft_stacksize(t_node *stack) 
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int count_bits(int n) //you have to pass the max element to this function and check how many bits we have to check for radix sort
{
    int count;

    count = 0;

    while (n > 0)
    {
        n >>= 1;
        count++;
    }
    return (count);
}

