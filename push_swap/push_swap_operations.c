/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:34:11 by ngungor           #+#    #+#             */
/*   Updated: 2025/07/29 15:45:15 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sa(t_node **a) // swap the first two nodes at the top of the stack a
{
	int	temp;

	if (!a || !(*a) || !((*a)->next))
		return ;
	temp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = temp;
}

void	sb(t_node **b) // swap the first two nodes at the top of the stack b
{
	int	temp;

	if (!b || !(*b) || !((*b)->next))
		return ;
	temp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = temp;	
}

void	pa(t_node **a, t_node **b) //this function is supposed to put the top value of b and put it to the top of a
{
	t_node	*temp;

	if (!b || !(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}

void	pb(t_node **a, t_node **b) //this function is supposed to put the top value of a and put it to the top of b
{
	t_node	*temp;

	if (!a || !(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	ra(t_node **a) //shift up all the elements of stack a by one. the first node becomes the last
{
	if (!a || !(*a) || !((*a)->next)) // if you pass an invalid pointer, or the stack is empty, or there is only one element in the stack therefore nothing to rotate
		return ;
	t_node	*first;
	t_node	*last;

	first = *a;
	last = *a;

	while (last->next)
		last = last->next;

	*a = first->next;
	first->next = NULL;
	last->next = first;
}


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
}

void	rr(t_node **a, t_node **b)
{
	rb(b);
	ra(a);
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
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
}

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
