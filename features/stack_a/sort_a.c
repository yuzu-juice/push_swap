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

static size_t	partition_a(t_stack *a, t_stack *b, int pivot, t_list *ops)
{
	size_t	i;
	size_t	size;
	size_t	pushed_count;
	size_t	ra_count;

	pushed_count = 0;
	ra_count = 0;
	size = a->top - a->bottom + 1;
	i = 0;
	while (i < size)
	{
		if (a->stack[a->top] < pivot)
		{
			pb(a, b, ops);
			pushed_count++;
		}
		else
		{
			ra(a, ops);
			ra_count++;
		}
		i++;
	}
	rotate_n_times(rra, a, ops, ra_count);
	return (pushed_count);
}

void	sort_a(t_stack *a, t_stack *b, t_list *ops)
{
	size_t	pushed_count;
	size_t	size;
	int		pivot;

	size = a->top - a->bottom + 1;
	pivot = get_pivot(a->stack, a->bottom, a->top);
	if (size <= 3)
	{
		sort_a_lte_three(a, b, ops);
		return ;
	}
	pushed_count = partition_a(a, b, pivot, ops);
	sort_a(a, b, ops);
	a->bottom = a->top + 1;
	push_n_times(pa, &(t_stacks){a, b}, ops, pushed_count);
	sort_a(a, b, ops);
}
