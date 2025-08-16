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


void	push(t_node **top, int value)
{
	t_node *new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		new_node = NULL;
		return ;
	}
	new_node->data = value;
	new_node->next = *top;
	*top = new_node;
}
void check_valid_numbers(char **numbers)
{
	int i = 0;
	int j;
	while (numbers[i])
	{
		if (!is_integer(numbers[i]))
			print_error_and_exit();
		j = i + 1;
		while (numbers[j])
		{
			if (ft_strcmp(numbers[i], numbers[j]) == 0)
				print_error_and_exit();
			j++;
		}
		i++;
	}
}
int	main(int argc, char **argv)
{
	char	**numbers;
	int	i;
	t_node *a;

	a = NULL;
	i = 0;
	if (argc < 2)
		print_error_and_exit();
	if (argc == 2)
		numbers = ft_split(argv[1], " ");
	else
		numbers = argv + 1;
	check_valid_numbers(numbers);
	push_a(&a, ft_atoi(numbers[0]));
	i = 1;
	while (numbers[i++])
		push_a(&a, ft_atoi(numbers[i]));
	while (b)
		push_a(&a, pop(&b));
	if (argc == 2)
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
void	print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
int	*integer_changer(char	**numbers)
{
	int	i;
	int	length;
	i = 0;
	length = ft_strlen(numbers);
	while (i < length)
	{
		numbers[i];
	}

}
int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		result = (result * 10) + *str - 48;
		str++;
	}
	return (result * sign);
}

int	is_integer(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}







