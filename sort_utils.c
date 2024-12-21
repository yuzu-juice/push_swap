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

int	is_sorted(t_stack stack)
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

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	i;

	min_index = get_min_index(stack_a->stack, 4);
	i = 0;
	while (i < stack_a->top - min_index)
	{
		ra(stack_a);
		i++;
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_more_than_five(t_stack *stack_a, t_stack *stack_b)
{
	int	max_index_b;
	int	min_index_b;
	int	max_index_a;
	int	min_index_a;
	int	largest_lt_index_b;
	int	smallest_gt_index_a;
	int	max;
	int	min;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->top > 2)
	{
		max_index_b = get_max_index(stack_b->stack, stack_b->top + 1);
		min_index_b = get_min_index(stack_b->stack, stack_b->top + 1);
		largest_lt_index_b = get_largest_number_index_lt(stack_b->stack, stack_b->top + 1, stack_a->stack[stack_a->top]);
		if (stack_a->stack[stack_a->top] >= stack_b->stack[max_index_b] || stack_a->stack[stack_a->top] <= stack_b->stack[min_index_b])
		{
			max = stack_b->stack[max_index_b];
			while (stack_b->stack[stack_b->top] != max)
				rb(stack_b);
			pb(stack_a, stack_b);
		}
		else
		{
			max = stack_b->stack[largest_lt_index_b];
			while (stack_b->stack[stack_b->top] != max)
				rb(stack_b);
			pb(stack_a, stack_b);
		}
		max_index_b = get_max_index(stack_b->stack, stack_b->top + 1);
		max = stack_b->stack[max_index_b];
		while (stack_b->stack[stack_b->top] != max)
			rb(stack_b);
	}
	sort_three(stack_a);
	while (stack_b->top > -1)
	{
		max_index_a = get_max_index(stack_a->stack, stack_a->top + 1);
		min_index_a = get_min_index(stack_a->stack, stack_a->top + 1);
		smallest_gt_index_a = get_smallest_number_index_gt(stack_a->stack, stack_a->top + 1, stack_b->stack[stack_b->top]);
		if (stack_b->stack[stack_b->top] >= stack_a->stack[max_index_a] || stack_b->stack[stack_b->top] <= stack_a->stack[min_index_a])
		{
			min = stack_a->stack[min_index_a];
			while (stack_a->stack[stack_a->top] != min)
				ra(stack_a);
			pa(stack_a, stack_b);
		}
		else
		{
			min = stack_a->stack[smallest_gt_index_a];
			while (stack_a->stack[stack_a->top] != min)
				ra(stack_a);
			pa(stack_a, stack_b);
		}
		min_index_a = get_min_index(stack_a->stack, stack_a->top + 1);
		min = stack_a->stack[min_index_a];
		while (stack_a->stack[stack_a->top] != min)
			ra(stack_a);
	}
}
