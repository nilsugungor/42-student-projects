#include "push_swap.h"

int	ft_atoi_strict(const char *str, int *out)
{
	long	result;
	int		sign;

	result = 0;
	sign = parse_sign(&str);
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		result = result * 10 + (*str - '0');
		if (sign == 1 && result > INT_MAX)
			return (0);
		if (sign == -1 && (-result) < INT_MIN)
			return (0);
		str++;
	}
	*out = (int)(sign * result);
	return (1);
}

void	check_valid(char **num, t_node **a, t_node **b, int need_split)
{
	int		i;
	int		count;
	int		n;
	int		*values;

	count = 0;
	while (num[count])
		count++;
	values = malloc(sizeof(int) * count);
	if (!values)
		print_error(num, a, b, need_split);
	i = 0;
	while (i < count)
	{
		if (is_empty_or_whitespace(num[i]) || !ft_atoi_strict(num[i], &n) 
			|| has_duplicate(values, i, n))
		{
			free(values);
			print_error(num, a, b, need_split);
		}
		values[i++] = n;
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

int	parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}
