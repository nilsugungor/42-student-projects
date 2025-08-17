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

void	sa(t_node **a) // swap the first two nodes at the top of the stack a
{
	int	temp;

	if (!a || !(*a) || !((*a)->next))
		return ;
	temp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = temp;
	write(1, "sa\n", 3);
}

void	sb(t_node **b) // swap the first two nodes at the top of the stack b
{
	int	temp;

	if (!b || !(*b) || !((*b)->next))
		return ;
	temp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = temp;
	write(1, "sb\n", 3);	
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
	write(1, "pa\n", 3);
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
	write(1, "pb\n", 3);
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
	write(1, "ra\n", 3);
}
