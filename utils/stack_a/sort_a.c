/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:47:17 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/24 19:38:35 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_a(t_stack *a, t_stack *b, int bottom)
{
	int		pivot;
	size_t	i;
	size_t	size;
	size_t	pushed_count;
	size_t	ra_count;

	pushed_count = 0;
	ra_count = 0;
	size = a->top - bottom + 1;
	if (size <= 4)
	{
		sort_a_lte_four(a, b, bottom);
		return ;
	}
	else
	{
		i = 0;
		pivot = get_pivot(a->stack, bottom, a->top);
		while (i < size)
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
			i++;
		}
		while (ra_count > 0)
		{
			rra(a);
			ra_count--;
		}
		sort_a(a, b, bottom);
		bottom = a->top + 1;
		while (pushed_count > 0)
		{
			pa(a, b);
			pushed_count--;
		}
		sort_a(a, b, bottom);
	}
}
