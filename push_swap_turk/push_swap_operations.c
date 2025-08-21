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

void	sa(t_node **a)
{
	int	temp;

	if (!a || !(*a) || !((*a)->next))
		return ;
	temp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = temp;
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	int	temp;

	if (!b || !(*b) || !((*b)->next))
		return ;
	temp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = temp;
	write(1, "sb\n", 3);
}

void	pa(t_node **a, t_node **b)
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

void	pb(t_node **a, t_node **b)
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

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !(*a) || !((*a)->next))
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}
