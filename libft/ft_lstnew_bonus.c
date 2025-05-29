/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:17:22 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 16:23:07 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
// Test function
void test_ft_lstnew()
{
    char *str = "hello";

    // Create new node with string content
    t_list *node = ft_lstnew(str);

    if (node == NULL)
    {
        printf("Test failed: returned NULL\n");
        return;
    }

    // Check content pointer is the same as input
    if (node->content == str)
        printf("Content test passed\n");
    else
        printf("Content test failed\n");

    // Check next pointer is NULL
    if (node->next == NULL)
        printf("Next pointer test passed\n");
    else
        printf("Next pointer test failed\n");

    free(node);
}

int main()
{
    test_ft_lstnew();
    return 0;
}*/
