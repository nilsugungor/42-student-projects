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
	if (length > 6)
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