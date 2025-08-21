/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalisation_of_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:27:43 by ngungor           #+#    #+#             */
/*   Updated: 2025/08/19 13:27:48 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **a, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = *a;
	*a = new_node;
}
