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

void	sort_stack(t_stacks *stacks, t_list *ops)
{
	t_stack	*a;
	t_stack	*b;

	a = &stacks->a;
	b = &stacks->b;
	if (is_sorted(a, true))
		return ;
	if (a->top < 4)
		sort_a_lte_four(stacks, ops);
	else
	{
		split_by_pivot(stacks, ops);
		sort_a(stacks, ops);
		sort_b(stacks, ops);
		apply_n_times(pa, stacks, ops, b->top + 1);
	}
}
