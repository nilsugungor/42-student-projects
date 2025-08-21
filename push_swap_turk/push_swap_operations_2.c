/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:29:33 by ngungor           #+#    #+#             */
/*   Updated: 2025/08/19 13:29:37 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (!b || !(*b) || !((*b)->next))
		return ;
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

void	rra(t_node **a)
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

void	rrb(t_node **b)
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
