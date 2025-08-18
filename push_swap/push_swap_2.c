#include "push_swap.h"

char	**get_numbers(int argc, char **argv, int *need_free_split)
{
	char	**numbers;

	*need_free_split = 0;
	if (argc == 2)
	{
		numbers = parse_args(argc, argv);
		*need_free_split = 1;
	}
	else
		numbers = argv + 1;
	return (numbers);
}

int	handle_sorted(t_node **a, char ***numbers, int need_free_split)
{
	free_stack(a);
	if (need_free_split)
		free_split(*numbers);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**numbers;
	t_node	*a;
	t_node	*b;
	int		need_free_split;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	numbers = get_numbers(argc, argv, &need_free_split);
	check_valid(numbers, &a, &b, need_free_split);
	fill_stack(&a, numbers, &b, need_free_split);
	if (is_sorted(a))
		return (handle_sorted(&a, &numbers, need_free_split));
	choose_sorting_algorithm(&a, &b);
	free_stack(&a);
	free_stack(&b);
	if (need_free_split)
		free_split(numbers);
	return (0);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	print_error(char **numbers, t_node **a, t_node **b, int need_free_split)
{
	write(2, "Error\n", 6);
	if (need_free_split)
		free_split(numbers);
	free_stack(a);
	free_stack(b);
	exit(EXIT_FAILURE);
}
