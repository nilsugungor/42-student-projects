/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanical_turk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:56:43 by ngungor           #+#    #+#             */
/*   Updated: 2025/08/21 13:56:44 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_all_except_three(t_node **a, t_node **b)
{
	int	length;
	int	i;
	i = 0;
	length = ft_stacksize(*a);
	if (length >= 6)
	{
		while (i < (length - 3))
		{
			pb(a, b);
			i++;
		}
	}
}

int	find_the_cheapest_move(t_node **a, t_node **b)
{

}
int	find_target_node(t_node *a, t_node *b)
{
	int	min_distance;
	int	distance;
	int	target_pos;
	int	best_pos; 
	t_node	*current_b;

	current_b = b;
	best_pos = 0;
	target_pos = 0;
	min_distance = INT_MAX;
	while (current_b)
	{
		if (distance > 0 && distance < min_distance)
		{
			distance = a->data - current_b->data;
			min_distance = distance;
			best_pos = target_pos;
		}
		current_b = current_b->next;
		target_pos++;
	}
	if (min_distance == INT_MAX)
		best_pos = find_max_index(b);
	return (best_pos);
}
