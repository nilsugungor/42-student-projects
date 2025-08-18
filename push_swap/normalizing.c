#include "push_swap.h"

void	normalize_and_sort(t_node **a, t_node **b)
{
	int	size;
	int	*arr;

	size = ft_stacksize(*a);
	arr = copy_list_into_array(a);
	if (!arr)
		exit(EXIT_FAILURE);
	heap_sort(arr, size);
	assign_index(*a, arr, size);
	free(arr);
	radix_sort(a, b);
}

int	*copy_list_into_array(t_node **a)
{
	t_node	*current;
	int		length;
	int		*arr;
	int		i;

	if (!a || !(*a))
		return (NULL);
	i = 0;
	length = ft_stacksize(*a);
	if (length == 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * length);
	if (!arr)
		return (NULL);
	current = *a;
	while (current)
	{
		arr[i] = current->data;
		current = current->next;
		i++;
	}
	return (arr);
}

void	heapify(int *arr, int n, int i)
{
	int	largest;
	int	left;
	int	right;
	int	temp;

	largest = i;
	left = (2 * i) + 1;
	right = (2 * i) + 2;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr, n, largest);
	}
}

void	heap_sort(int *arr, int n)
{
	int	i;
	int	temp;

	if (n <= 1)
		return ;
	i = n / 2 -1;
	while (i >= 0)
	{
		heapify(arr, n, i);
		i--;
	}
	i = n - 1;
	while (i >= 0)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
		i--;
	}
}

int	count_bits(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n >>= 1;
		count++;
	}
	if (count == 0)
		count = 1;
	return (count);
}
