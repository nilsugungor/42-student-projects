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
	struct s_node *next;
} t_node;

int	is_integer(const char *str);
int	ft_atoi(const char *str);
int	*integer_changer(char	**numeros);
void	push(t_node **top, int value);
