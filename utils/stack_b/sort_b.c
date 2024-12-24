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

static size_t	partition_b(t_stack *a, t_stack *b, int bottom, int pivot)
{
	size_t	i;
	size_t	size;
	size_t	pushed_count;
	size_t	rb_count;

	pushed_count = 0;
	rb_count = 0;
	size = b->top - bottom + 1;
	i = 0;
	while (i++ < size)
	{
		if (b->stack[b->top] < pivot)
		{
			pa(a, b);
			pushed_count++;
		}
		else
		{
			rb(b);
			rb_count++;
		}
	}
	while (rb_count-- > 0)
		rrb(b);
	return (pushed_count);
}

void	sort_b(t_stack *a, t_stack *b, int bottom)
{
	size_t	pushed_count;
	size_t	size;
	int		pivot;

	size = b->top - bottom + 1;
	pivot = get_pivot(b->stack, bottom, b->top);
	if (size <= 4)
	{
		sort_b_lte_four(a, b, bottom);
		return ;
	}
	pushed_count = partition_b(a, b, bottom, pivot);
	sort_b(a, b, bottom);
	bottom = b->top + 1;
	while (pushed_count-- > 0)
		pb(a, b);
	sort_b(a, b, bottom);
}
