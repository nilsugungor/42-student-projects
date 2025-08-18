#include "push_swap.h"

void	rb(t_node **b) //shift up all the elements of stack b by one. the first node becomes the last
{
	if (!b || !(*b) || !((*b)->next)) // if you pass an invalid pointer, or the stack is empty, or there is only one element in the stack therefore nothing to rotate
		return ;
	t_node	*first;
	t_node	*last;

	first = *b;
	last = *b;

	while (last->next)
		last = last->next;

	*b = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rb(b);
	ra(a);
	write(1, "rr\n", 3);
}

void	rra(t_node **a) //shift down all the elements of stack a. last element becomes the first one
{
	t_node	*prev;
	t_node	*last;

	if (!a || !(*a) || !((*a)->next))
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_node **b) //shift down all the elements of stack b. last element becomes the first one
{
	t_node	*prev;
	t_node	*last;

	if (!b || !(*b) || !((*b)->next))
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}