/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:30:21 by ngungor           #+#    #+#             */
/*   Updated: 2025/08/19 13:30:24 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **a)
{
	if (!a || !(*a) || !(*a)->next->next || !(*a)->next)
		return ;
	if ((*a)->data > (*a)->next->data)
		sa(a);
	if ((*a)->next->data > (*a)->next->next->data)
	{
		rra(a);
		sa(a);
	}
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	sort_5(t_node **a, t_node **b)
{
	int	length;

	length = ft_stacksize(*a);
	if (length == 5)
	{
		pb(a, b);
		pb(a, b);
		sort_3(a);
		insert_by_value(a, b);
		insert_by_value(a, b);
	}
	else if (length == 4)
	{
		pb(a, b);
		sort_3(a);
		insert_by_value(a, b);
	}
}

void	sort_2(t_node **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
