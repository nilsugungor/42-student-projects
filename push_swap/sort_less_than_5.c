#include "push_swap.h"
void    sort_3(t_node **a)
{
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
void find_target(t_node **a, t_node **b)
{
    t_node *current;

    current = *a;
    

}
void    sort_5(t_node **a, t_node **b)
{
    int length;

    length = ft_stacksize(&a);
    if (length == 5)
    {
        pb(b, a);
        pb(b, a);
        sort_3(a);

    }
    if (length == 4)
    {
        pb(b, a);
        sort_3(a);
    }

}