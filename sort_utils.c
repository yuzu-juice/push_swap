/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:43:26 by takitaga          #+#    #+#             */
/*   Updated: 2024/09/20 00:48:29 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	is_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.top)
	{
		if (stack.stack[i] < stack.stack[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	sort_three(t_stack *stack)
{
	if (get_max_index(stack->stack, 3) == stack->top)
		ra(stack);
	if (get_max_index(stack->stack, 3) == stack->top - 1)
		rra(stack);
	if (stack->stack[stack->top] > stack->stack[stack->top - 1])
		sa(stack);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min_index;
	int	i;

	min_index = get_min_index(a->stack, 4);
	i = 0;
	while (i < a->top - min_index)
	{
		ra(a);
		i++;
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_more_than_five(t_stack *a, t_stack *b)
{
	int	max_index_b;
	int	min_index_b;
	int	max_index_a;
	int	min_index_a;
	int	largest_lt_index_b;
	int	smallest_gt_index_a;
	int	max;
	int	min;

	pb(a, b);
	pb(a, b);
	while (a->top > 2)
	{
		max_index_b = get_max_index(b->stack, b->top + 1);
		min_index_b = get_min_index(b->stack, b->top + 1);
		largest_lt_index_b = get_largest_number_index_lt(b->stack, b->top + 1, a->stack[a->top]);
		if (a->stack[a->top] >= b->stack[max_index_b] || a->stack[a->top] <= b->stack[min_index_b])
		{
			max = b->stack[max_index_b];
			while (b->stack[b->top] != max)
				rb(b);
			pb(a, b);
		}
		else
		{
			max = b->stack[largest_lt_index_b];
			while (b->stack[b->top] != max)
				rb(b);
			pb(a, b);
		}
		max_index_b = get_max_index(b->stack, b->top + 1);
		max = b->stack[max_index_b];
		while (b->stack[b->top] != max)
			rb(b);
	}
	sort_three(a);
	while (b->top > -1)
	{
		max_index_a = get_max_index(a->stack, a->top + 1);
		min_index_a = get_min_index(a->stack, a->top + 1);
		smallest_gt_index_a = get_smallest_number_index_gt(a->stack, a->top + 1, b->stack[b->top]);
		if (b->stack[b->top] >= a->stack[max_index_a] || b->stack[b->top] <= a->stack[min_index_a])
		{
			min = a->stack[min_index_a];
			while (a->stack[a->top] != min)
				ra(a);
			pa(a, b);
		}
		else
		{
			min = a->stack[smallest_gt_index_a];
			while (a->stack[a->top] != min)
				ra(a);
			pa(a, b);
		}
		min_index_a = get_min_index(a->stack, a->top + 1);
		min = a->stack[min_index_a];
		while (a->stack[a->top] != min)
			ra(a);
	}
}
