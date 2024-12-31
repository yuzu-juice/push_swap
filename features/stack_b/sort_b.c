/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:47:22 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/24 19:38:42 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	handle_push(t_stack *a, t_stack *b, t_list *ops, size_t *count)
{
	pa(a, b, ops);
	(*count)++;
}

static void	handle_rotate(t_stack *b, t_list *ops, size_t *count)
{
	rb(b, ops);
	(*count)++;
}

static _Bool	will_not_pa(t_stack *b, size_t i, size_t size, int pivot)
{
	size_t	iter;

	iter = 0;
	while (i < size)
	{
		if (b->stack[b->top - iter] > pivot)
			return (false);
		i++;
		iter++;
	}
	return (true);
}

static size_t	partition_b(t_stack *a, t_stack *b, int pivot, t_list *ops)
{
	size_t	i;
	size_t	size;
	t_count	count;

	count.push = 0;
	count.rotate = 0;
	size = b->top - b->bottom + 1;
	i = 0;
	while (i < size)
	{
		if (b->stack[b->top] > pivot)
		{
			handle_push(a, b, ops, &count.push);
		}
		else
		{
			if (will_not_pa(b, i, size, pivot))
				break ;
			handle_rotate(b, ops, &count.rotate);
		}
		i++;
	}
	rotate_optimally(b, ops, (t_rot){rb, rrb}, count.rotate);
	return (count.push);
}

void	sort_b(t_stack *a, t_stack *b, t_list *ops)
{
	size_t	pushed_count;
	size_t	size;
	int		pivot;
	int		tmp;

	size = b->top - b->bottom + 1;
	if (is_sorted(b, false))
		return ;
	pivot = get_pivot(b->stack, b->bottom, b->top);
	if (size <= 3)
	{
		sort_b_lte_three(b, ops);
		return ;
	}
	pushed_count = partition_b(a, b, pivot, ops);
	sort_b(a, b, ops);
	tmp = a->bottom;
	a->bottom = a->top - pushed_count + 1;
	sort_a(a, b, ops);
	a->bottom = tmp;
	push_n_times(pb, &(t_stacks){a, b}, ops, pushed_count);
}
