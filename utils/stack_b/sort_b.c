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

void	sort_b(t_stack *a, t_stack *b, int bottom)
{
	int		pivot;
	size_t	i;
	size_t	size;
	size_t	pushed_count;
	size_t	rb_count;

	pushed_count = 0;
	rb_count = 0;
	size = b->top - bottom + 1;
	if (size <= 4)
	{
		sort_b_lte_four(a, b, bottom);
		return ;
	}
	else
	{
		i = 0;
		pivot = get_pivot(b->stack, bottom, b->top);
		while (i < size)
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
			i++;
		}
		while (rb_count > 0)
		{
			rrb(b);
			rb_count--;
		}
		sort_b(a, b, bottom);
		bottom = b->top + 1;
		while (pushed_count > 0)
		{
			pb(a, b);
			pushed_count--;
		}
		sort_b(a, b, bottom);
	}
}
