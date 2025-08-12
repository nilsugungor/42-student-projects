#include "push_swap.h"

void    sort_3(t_node **a)
{
    if (!a || !(*a) || !(*a)->next->next)
        return ;
    if ((*a)->data > (*a)->next->data)
        sa(a);
    if ((*a)->next->data > (*a)->next->next->data)
    {
        rra(a);
        sa(a);
    }
    if ((*a)->data > (*a)->next->data)
        sa(a);
}

void	insert_by_value(t_node **a, t_node **b)
{
	t_node	*current;
	int	count;
	int	i;

	count = 0;
    i = 0;
    if (!(*b))
        return ;
	if (!(*a) || (*a)->data > (*b)->data)
        return ((void)pa(a, b));
	current = *a;
	while (current->next && current->next->data <= (*b)->data)
	{
		current = current->next;
		count++;
	}
    if (current->next == NULL)
        return ((void)(pa(a, b), ra(a)));
	while (i++ < count)
		ra(a);
	pa(a, b);
	while (count--)
		rra(a);
}

void    sort_5(t_node **a, t_node **b)
{
    int length;

    length = ft_stacksize(*a);
    if (length == 5)
    {
        pb(a, b);
        pb(a, b);
        sort_3(a);
        insert_by_value(a, b);
        insert_by_value(a, b);
    }
    else if (length == 4)
    {
        pb(a, b);
        sort_3(a);
        insert_by_value(a, b);
    }
}