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
			print_error_and_exit(numbers, a, b, need_free_split);
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
void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
int	main(int argc, char **argv)
{
	char	**numbers;
	t_node	*a = NULL;
	t_node	*b = NULL;
	int	need_free_split;
	if (argc < 2)
		print_error();
	if (argc == 2)
	{
		numbers = parse_args(argc, argv);
		need_free_split = 1;
	}
	else
	{
		numbers = argv + 1;
		need_free_split = 0;
	}
	check_valid_numbers(numbers, &a, &b, need_free_split);
	fill_stack(&a, numbers, &b, need_free_split);
	if (is_sorted(a))
	{
		free_stack(&a);
		if (need_free_split)
			free_split(numbers);
		return (0);
	}
	choose_sorting_algorithm(&a, &b);
	free_stack(&a);
	free_stack(&b);
	if (need_free_split)
		free_split(numbers);
	return (0);
}
void	free_split(char **arr)
{
	int i = 0;
	if (!arr)
		return;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
void	print_error_and_exit(char **numbers, t_node **a, t_node **b, int need_free_split)
{
	write(2, "Error\n", 6);
	if (need_free_split)
		free_split(numbers);
	free_stack(a);
	free_stack(b);
	exit(EXIT_FAILURE);
}
int	ft_atoi_strict(const char *str, int *out)
{
	long	result = 0;
	int		sign = 1;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
			return (0);
		str++;
	}
	*out = (int)(sign * result);
	return (1);
}
//if the string is empy or no arguments psuh swap displays npothing
void	check_valid_numbers(char **numbers, t_node **a, t_node **b, int need_free_split)
{
	int	i;
	int	n;
	int	count;
	int *values;

	i = 0;
	count = 0;
	while (numbers[count])
		count++;
	values = malloc(sizeof(int) * count);
	if (!values)
		print_error_and_exit(numbers, a, b, need_free_split);
	while (i < count)
	{
		if (is_empty_or_whitespace(numbers[i]))
		{
			free(values);
			print_error_and_exit(numbers, a, b, need_free_split);
		}
		if (!ft_atoi_strict(numbers[i], &n))
		{
			free(values);
			print_error_and_exit(numbers, a, b, need_free_split);
		}
		if (has_duplicate(values, i, n))
		{
			free(values);
			print_error_and_exit(numbers, a, b, need_free_split);
		}
		values[i] = n;
		i++;
	}
	free(values);
}
int	has_duplicate(int *values, int size, int n)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (values[j] == n)
			return (1);
		j++;
	}
	return (0);
}

int	is_empty_or_whitespace(const char *str)
{
	while (*str)
	{
		if (!(*str == ' ' || (*str >= 9 && *str <= 13)))
			return (0);
		str++;
	}
	return (1);
}


