/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:25:37 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/24 22:01:52 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	handle_push(t_stacks *stacks, t_list *ops, size_t *count)
{
	pb(stacks, ops);
	(*count)++;
}

static void	handle_rotate(t_stacks *stacks, t_list *ops, size_t *count)
{
	ra(stacks, ops);
	(*count)++;
}

static _Bool	will_not_pb(t_stack *a, size_t i, size_t size, int pivot)
{
	size_t	iter;

	iter = 0;
	while (i < size)
	{
		if (a->stack[a->top - iter] < pivot)
			return (false);
		i++;
		iter++;
	}
	return (true);
}

static size_t	partition_a(t_stacks *stacks, int pivot, t_list *ops)
{
	size_t	i;
	size_t	size;
	t_count	count;
	t_stack	*a;

	a = &stacks->a;
	count.push = 0;
	count.rotate = 0;
	size = a->top - a->bottom + 1;
	i = 0;
	while (i < size)
	{
		if (a->stack[a->top] < pivot)
			handle_push(stacks, ops, &count.push);
		else
		{
			if (will_not_pb(a, i, size, pivot))
				break ;
			handle_rotate(stacks, ops, &count.rotate);
		}
		i++;
	}
	rotate_a_opt(stacks, ops, (t_rot){ra, rra}, count.rotate);
	return (count.push);
}

void	sort_a(t_stacks *stacks, t_list *ops)
{
	size_t	pushed_count;
	size_t	size;
	int		pivot;
	int		tmp;

	size = stacks->a.top - stacks->a.bottom + 1;
	if (is_sorted(&stacks->a, true))
		return ;
	if (size <= 4)
	{
		sort_a_lte_four(stacks, ops);
		return ;
	}
	pivot = get_pivot(stacks->a.stack, stacks->a.bottom, stacks->a.top);
	pushed_count = partition_a(stacks, pivot, ops);
	sort_a(stacks, ops);
	tmp = stacks->b.bottom;
	stacks->b.bottom = stacks->b.top - pushed_count + 1;
	sort_b(stacks, ops);
	stacks->b.bottom = tmp;
	apply_n_times(pa, stacks, ops, pushed_count);
}
