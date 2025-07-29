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

int	main(int argc, char **argv)
{
	char	**numeros;
	int	i;
	int	j;

	i = 1;
	if (argc == 2)
		numeros = ft_split(argv[1], " ");

	if (argc > 2)
	{
		while (i < argc - 1)
		{
			j = i + 1;
			while (j < argc)
			{
				if (argv[i] == argv[j])
				{
					write(1, "Error\n", 6);
					exit(EXIT_FAILURE);
				}
				j++;
			}
			if (!is_integer(argv[i]))
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
}
int	*integer_changer(char	**numeros)
{
	int	i;
	int	length;
	i = 0;
	length = ft_strlen(numeros);
	while (i < length)
	{
		numeros[i];
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







