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

static void	handle_push(t_stack *a, t_stack *b, t_list *ops, size_t *count)
{
	pb(a, b, ops);
	(*count)++;
}

static void	handle_rotate(t_stack *a, t_list *ops, size_t *count)
{
	ra(a, ops);
	(*count)++;
}

static _Bool	will_not_pb(t_stack *a, size_t i, size_t size, int pivot)
{
	size_t	iter;

	iter = 0;
	while (i < size)
	{
		if (a->stack[a->top - iter] < pivot)
			return (FALSE);
		i++;
		iter++;
	}
	return (TRUE);
}

static size_t	partition_a(t_stack *a, t_stack *b, int pivot, t_list *ops)
{
	size_t	i;
	size_t	size;
	t_count	count;

	count.push = 0;
	count.rotate = 0;
	size = a->top - a->bottom + 1;
	i = 0;
	while (i < size)
	{
		if (a->stack[a->top] < pivot)
			handle_push(a, b, ops, &count.push);
		else
		{
			if (will_not_pb(a, i, size, pivot))
				break ;
			handle_rotate(a, ops, &count.rotate);
		}
		i++;
	}
	rotate_optimally(a, ops, (t_rot){ra, rra}, count.rotate);
	return (count.push);
}

void	sort_a(t_stack *a, t_stack *b, t_list *ops)
{
	size_t	pushed_count;
	size_t	size;
	int		pivot;
	int		tmp;

	size = a->top - a->bottom + 1;
	pivot = get_pivot(a->stack, a->bottom, a->top);
	if (size <= 3)
	{
		sort_a_lte_three(a, b, ops);
		return ;
	}
	pushed_count = partition_a(a, b, pivot, ops);
	sort_a(a, b, ops);
	tmp = b->bottom;
	b->bottom = b->top - pushed_count + 1;
	sort_b(a, b, ops);
	b->bottom = tmp;
	push_n_times(pa, &(t_stacks){a, b}, ops, pushed_count);
}
