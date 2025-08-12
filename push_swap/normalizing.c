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

int *normalize_array(int arr[], int n) //this function basically gets the array from the previous function and normalizes it in the range of 0 and n - 1
{
    int min;
    int max;
    int i;

    min = arr[0];
    max = arr[0];
    i = 0;
    while (i < n)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        arr[i] = (arr[i] - min) * (n - 1) / (max - min);
        i++;
    }
    return arr;
}

void    array_to_stack(t_node **index, int arr[]) //need to put them in the stack under the index variable somehow? or do a 2d array
{
    t_node  *current;


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




//HEAPSORT
// void    swap(int *a, int *b)
// {
//     int temp;

//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void    heapify(int normalize[], int n, int i)
// {
//     int largest;
//     int left;
//     int right;

//     largest = i;
//     left = 2 * i + 1;
//     right = 2 * i + 2;

//     if (left < n && normalize[left] > normalize[largest])
//         largest = left;
//     if (right < n && normalize[right] > normalize[largest])
//         largest = right;
//     if (largest != i)
//     {
//         swap(&normalize[i], &normalize[largest]);
//         heapify(normalize, n, largest);
//     }
// }

// int    *heap_sort(int normalize[], int n)
// {
//     int i;

//     i = n / 2 - 1;
//     while (i >= 0)
//         heapify(normalize, n, i);
//     i = n - 1;
//     while (i--)
//     {
//         swap(&normalize[0], &normalize[i]);
//         heapify(normalize, i, 0);
//     }
//     return (normalize);
// }










































