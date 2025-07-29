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

void	sa(t_node **top)
{
	int	temp;

	if (!top || !(*top) || !((*top)->next))
		return ;
	temp = (*top)->data;
	(*top)->data = (*top)->next->data;
	(*top)->next->data = temp;	
}

void	sb(t_node **top)
{
	int	temp;

	if (!top || !(*top) || !((*top)->next))
		return ;
	temp = (*top)->data;
	(*top)->data = (*top)->next->data;
	(*top)->next->data = temp;
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
}

void	pb(t_node **b, t_node **a)
{
	t_node	*temp;

	if (!a || !(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}
static int	ft_stacksize(t_node **a)
{
	int	i;
	t_node	*current;

	i = 0;
	if (!a || !(*a))
		return (0);
	current = *a;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
void	ra(t_node **a)
{
	t_node	*temp;

}
