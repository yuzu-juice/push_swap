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

static size_t	partition_a(t_stack *a, t_stack *b, int bottom, int pivot)
{
	size_t	i;
	size_t	size;
	size_t	pushed_count;
	size_t	ra_count;

	pushed_count = 0;
	ra_count = 0;
	size = a->top - bottom + 1;
	i = 0;
	while (i++ < size)
	{
		if (a->stack[a->top] < pivot)
		{
			pb(a, b);
			pushed_count++;
		}
		else
		{
			ra(a);
			ra_count++;
		}
	}
	while (ra_count-- > 0)
		rra(a);
	return (pushed_count);
}

void	sort_a(t_stack *a, t_stack *b, int bottom)
{
	size_t	pushed_count;
	size_t	size;
	int		pivot;

	size = a->top - bottom + 1;
	pivot = get_pivot(a->stack, bottom, a->top);
	if (size <= 4)
	{
		sort_a_lte_four(a, b, bottom);
		return ;
	}
	pushed_count = partition_a(a, b, bottom, pivot);
	sort_a(a, b, bottom);
	bottom = a->top + 1;
	while (pushed_count-- > 0)
		pa(a, b);
	sort_a(a, b, bottom);
}
