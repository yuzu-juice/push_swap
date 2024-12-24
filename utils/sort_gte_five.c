/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:36:15 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/24 00:36:34 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	sort_more_than_five(t_stack *a, t_stack *b)
// {
// 	int	max_index_b;
// 	int	min_index_b;
// 	int	max_index_a;
// 	int	min_index_a;
// 	int	largest_lt_index_b;
// 	int	smallest_gt_index_a;
// 	int	max;
// 	int	min;
//
// 	pb(a, b);
// 	pb(a, b);
// 	while (a->top > 2)
// 	{
// 		max_index_b = get_max_index(b->stack, b->top + 1);
// 		min_index_b = get_min_index(b->stack, b->top + 1);
// 		largest_lt_index_b = get_largest_num_index_lt(b->stack, b->top + 1, a->stack[a->top]);
// 		if (a->stack[a->top] >= b->stack[max_index_b] || a->stack[a->top] <= b->stack[min_index_b])
// 		{
// 			max = b->stack[max_index_b];
// 			while (b->stack[b->top] != max)
// 				rb(b);
// 			pb(a, b);
// 		}
// 		else
// 		{
// 			max = b->stack[largest_lt_index_b];
// 			while (b->stack[b->top] != max)
// 				rb(b);
// 			pb(a, b);
// 		}
// 		max_index_b = get_max_index(b->stack, b->top + 1);
// 		max = b->stack[max_index_b];
// 		while (b->stack[b->top] != max)
// 			rb(b);
// 	}
// 	sort_three(a);
// 	while (b->top > -1)
// 	{
// 		max_index_a = get_max_index(a->stack, a->top + 1);
// 		min_index_a = get_min_index(a->stack, a->top + 1);
// 		smallest_gt_index_a = get_smallest_num_index_gt(a->stack, a->top + 1, b->stack[b->top]);
// 		if (b->stack[b->top] >= a->stack[max_index_a] || b->stack[b->top] <= a->stack[min_index_a])
// 		{
// 			min = a->stack[min_index_a];
// 			while (a->stack[a->top] != min)
// 				ra(a);
// 			pa(a, b);
// 		}
// 		else
// 		{
// 			min = a->stack[smallest_gt_index_a];
// 			while (a->stack[a->top] != min)
// 				ra(a);
// 			pa(a, b);
// 		}
// 		min_index_a = get_min_index(a->stack, a->top + 1);
// 		min = a->stack[min_index_a];
// 		while (a->stack[a->top] != min)
// 			ra(a);
// 	}
// }

void	sort_gte_five(t_stack *a, t_stack *b, int bottom)
{
	size_t	pushed_count;
	int		pivot;
	size_t	i;
	size_t	size;

	if (bottom >= a->top)
		return ;
	pushed_count = 0;
	i = 0;
	size = a->top - bottom + 1;

	// ft_printf("initial stack\n");
	// print_stack(a, b, 10);
	// ft_printf("size: %d\n", size);

	pivot = get_pivot(a->stack, 0, a->top);
	// ft_printf("pivot: %d\n", pivot);
	while (i < size)
	{
		if (a->stack[a->top] < pivot)
		{
			pb(a, b);
			pushed_count++;
		}
		else
			ra(a);
		i++;
		// print_stack(a, b, 10);
	}
	size -= pushed_count;
	if (size <= 4)
	{
		sort_lte_four(a, b, bottom);
		// print_stack(a, b, 10);
		bottom += a->top - bottom + 1;
		while (pushed_count > 0)
		{
			// ft_printf("pushed_count: %d\n", pushed_count);
			pa(a, b);
			// print_stack(a, b, 10);
			pushed_count--;
		}
		// ft_printf("bottom: %d, top: %d\n", bottom, a->top);
		sort_lte_four(a, b, bottom);
	}
	else
		sort_gte_five(a, b, bottom);
}
