/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_pivot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:41:13 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/24 12:54:52 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	split_by_pivot(t_stacks *stacks, t_list *ops)
{
	int		pivot;
	int		first_quartile;
	int		i;
	int		size;
	t_stack	*a;

	a = &stacks->a;
	size = a->top + 1;
	i = 0;
	pivot = get_pivot(a->stack, 0, a->top);
	first_quartile = get_first_quartile(a->stack, 0, a->top);
	while (i < size)
	{
		if (a->stack[a->top] < first_quartile)
		{
			pb(stacks, ops);
			rb(stacks, ops);
		}
		else if (a->stack[a->top] < pivot)
			pb(stacks, ops);
		else
			ra(stacks, ops);
		i++;
	}
}
