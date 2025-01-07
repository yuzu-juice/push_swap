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

static void	handle_push(t_stacks *stacks, t_list *ops, size_t *count)
{
	pa(stacks, ops);
	(*count)++;
}

static void	handle_rotate(t_stacks *stacks, t_list *ops, size_t *count)
{
	rb(stacks, ops);
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

static size_t	partition_b(t_stacks *stacks, int pivot, t_list *ops)
{
	size_t	i;
	size_t	size;
	t_count	count;

	count.push = 0;
	count.rotate = 0;
	size = stacks->b.top - stacks->b.bottom + 1;
	i = 0;
	while (i < size)
	{
		if (stacks->b.stack[stacks->b.top] > pivot)
		{
			handle_push(stacks, ops, &count.push);
		}
		else
		{
			if (will_not_pa(&stacks->b, i, size, pivot))
				break ;
			handle_rotate(stacks, ops, &count.rotate);
		}
		i++;
	}
	rotate_b_opt(stacks, ops, (t_rot){rb, rrb}, count.rotate);
	return (count.push);
}

void	sort_b(t_stacks *stacks, t_list *ops)
{
	size_t	pushed_count;
	size_t	size;
	int		pivot;
	int		tmp;

	size = stacks->b.top - stacks->b.bottom + 1;
	if (is_sorted(&stacks->b, false))
		return ;
	pivot = get_pivot(stacks->b.stack, stacks->b.bottom, stacks->b.top);
	if (size <= 4)
	{
		sort_b_lte_four(stacks, ops);
		return ;
	}
	pushed_count = partition_b(stacks, pivot, ops);
	sort_b(stacks, ops);
	tmp = stacks->a.bottom;
	stacks->a.bottom = stacks->a.top - pushed_count + 1;
	sort_a(stacks, ops);
	stacks->a.bottom = tmp;
	apply_n_times(pb, stacks, ops, pushed_count);
}
