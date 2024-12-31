/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:12:18 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/29 23:14:38 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

_Bool	sort_stack(t_stack *a, t_stack *b, t_list *ops)
{
	if (is_sorted(a, TRUE))
		return (TRUE);
	if (a->top < 4)
		sort_a_lte_four(a, b, ops);
	else
	{
		split_by_pivot(a, b, ops);
		sort_a(a, b, ops);
		sort_b(a, b, ops);
		push_n_times(pa, &(t_stacks){a, b}, ops, b->top + 1);
	}
	return (TRUE);
}
