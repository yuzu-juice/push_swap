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

static size_t	partition_b(t_stack *a, t_stack *b, int pivot, t_list *ops)
{
	size_t	i;
	size_t	size;
	size_t	pushed_count;
	size_t	rb_count;

	pushed_count = 0;
	rb_count = 0;
	size = b->top - b->bottom + 1;
	i = 0;
	while (i++ < size)
	{
		if (b->stack[b->top] < pivot)
		{
			pa(a, b, ops);
			pushed_count++;
		}
		else
		{
			rb(b, ops);
			rb_count++;
		}
	}
	while (rb_count-- > 0)
		rrb(b, ops);
	return (pushed_count);
}

void	sort_b(t_stack *a, t_stack *b, t_list *ops)
{
	size_t	pushed_count;
	size_t	size;
	int		pivot;

	size = b->top - b->bottom + 1;
	pivot = get_pivot(b->stack, b->bottom, b->top);
	if (size <= 4)
	{
		sort_b_lte_four(a, b, ops);
		return ;
	}
	pushed_count = partition_b(a, b, pivot, ops);
	sort_b(a, b, ops);
	b->bottom = b->top + 1;
	while (pushed_count-- > 0)
		pb(a, b, ops);
	sort_b(a, b, ops);
}