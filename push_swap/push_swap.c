/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:42:15 by ngungor           #+#    #+#             */
/*   Updated: 2025/07/28 14:50:46 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sorting_algorithm(t_node **a, t_node **b)
{
	int	length;

	length = ft_stacksize(*a);
	if (length == 1)
		return ;
	else if (length == 2)
		sort_2(a);
	else if (length == 3)
		sort_3(a);
	else if (length == 4 || length == 5)
		sort_5(a, b);
	else
		normalize_and_sort(a, b);
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	fill_stack(t_node **a, char **numbers, t_node **b, int need_free_split)
{
	int	i;
	int	n;
	int	count;

	count = count_args(numbers);
	i = count - 1;
	while (i >= 0)
	{
		if (!ft_atoi_strict(numbers[i], &n))
			print_error(numbers, a, b, need_free_split);
		push_a(a, n);
		i--;
	}
}

char	**parse_args(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	else
		return (argv + 1);
}
