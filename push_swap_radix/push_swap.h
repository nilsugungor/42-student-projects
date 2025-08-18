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
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node {
	int	data;
	int	index;
	struct s_node *next;
}	t_node;

void	push_a(t_node **a, int value);
void	sa(t_node **a);
void	sb(t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	choose_sorting_algorithm(t_node **a, t_node **b);
void	sort_2(t_node **a);
void	sort_3(t_node **a);
void	sort_5(t_node **a, t_node **b);
void	normalize_and_sort(t_node **a, t_node **b);
void	radix_sort(t_node **a, t_node **b);
void	assign_index(t_node *a, int *sorted_array, int size);
int		ft_stacksize(t_node *stack);
int		is_sorted(t_node *a);
int	ft_isdigit(int c);
void	free_stack(t_node **stack);
void	fill_stack(t_node **a, char **numbers, t_node **b, int need_free_split);
char	**parse_args(int argc, char **argv);
void	free_split(char **arr);
void	print_error_and_exit(char **numbers, t_node **a, t_node **b, int need_free_split);
int		ft_atoi_strict(const char *str, int *out);
void	check_valid_numbers(char **numbers, t_node **a, t_node **b, int need_free_split);
int		has_duplicate(int *values, int size, int n);
int		is_empty_or_whitespace(const char *str);
char	**ft_split(char const *s, char c);
int		*copy_list_into_array(t_node **a);
void	heap_sort(int *arr, int n);
void	heapify(int *arr, int n, int i);
int		count_bits(int n);
void	insert_by_value(t_node **a, t_node **b);

#endif