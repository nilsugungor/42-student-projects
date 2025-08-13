#include "push_swap.h"

int	ft_stacksize(t_node *stack) 
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int *copy_list_to_array(t_node **a) //this function gets the nodes from the stack and puts them in an array
{
    int length;
    int *normalize;
    int i;

    i = 0;
    t_node  *current;
    current = *a;
    length = ft_stacksize(*a);
    normalize = malloc(length * sizeof(int));
    if (!normalize)
        return (NULL);
    while (current)
    {
        normalize[i] = current->data;
        i++;
        current = current->next;
    }
    return (normalize);
}

void    swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    heapify(int normalize[], int n, int root_index)
{
    int largest;
    int left;
    int right;

    largest = root_index;
    left = 2 * root_index + 1;
    right = 2 * root_index + 2;

    if (left < n && normalize[left] > normalize[largest])
        largest = left;
    if (right < n && normalize[right] > normalize[largest])
        largest = right;
    if (largest != root_index)
    {
        swap(&normalize[root_index], &normalize[largest]);
        heapify(normalize, n, largest);
    }
}

int    *heap_sort(int normalize[], int n)
{
    int root_index;
    int i;
    int *sorted;

    sorted = (int *)malloc(sizeof(int) * n);
    if (!sorted)
        return (NULL);
    i = 0;
    root_index = n / 2 - 1;
    while (i < n)
    {
        sorted[i] = normalize[i];
        i++;
    }
    while (root_index >= 0)
    {
        heapify(sorted, n, root_index);
        root_index--;
    }
    root_index = n - 1;
    while (root_index-- > 0)
    {
        swap(&sorted[0], &sorted[root_index]);
        heapify(sorted, root_index, 0);
    }
    return (sorted);
}

int     binary_search(int n, int target, int *normalize)
{
    int mid;
    int left;
    int right;

    left = 0;
    right = n - 1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (normalize[mid] == target)
            return (mid);
        else if (normalize[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (-1);
}

int *binary_search_write(int target)
{

}

void    array_to_stack(t_node **a, int *normalize) //need to put them in the stack under the index variable somehow? or do a 2d array
{
    t_node  *current;
    int i;

    current = *a;
    i = 0;
    while (current)
    {
        current->index = normalize[i];
        i++;
        current = current->next;
    }
}

int count_bits(int n) //you have to pass the max element to this function and check how many bits we have to check for radix sort
{
    int count;

    count = 0;

    while (n > 0)
    {
        n >>= 1;
        count++;
    }
    return (count);
}

