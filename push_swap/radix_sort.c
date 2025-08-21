/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:30:07 by ngungor           #+#    #+#             */
/*   Updated: 2025/08/19 13:30:10 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node *a, int *sorted_array, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->data == sorted_array[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	radix_sort(t_node **a, t_node **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = ft_stacksize(*a);
	max_bits = count_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
