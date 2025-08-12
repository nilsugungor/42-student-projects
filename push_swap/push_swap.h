/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:37:16 by ngungor           #+#    #+#             */
/*   Updated: 2025/07/29 14:09:01 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node {
	int	data;
	int	index;
	int	length;
	struct s_node *next;
} t_node;

t_node	*a = NULL;
t_node	*b = NULL;

int	is_integer(const char *str);
int	ft_atoi(const char *str);
int	*integer_changer(char	**numeros);
int	ft_stacksize(t_node *stack);
void	push(t_node **top, int value);
void	sa(t_node **a);
void	sb(t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);