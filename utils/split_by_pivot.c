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

void	split_by_pivot(t_stack *a, t_stack *b, t_list *ops)
{
	int	pivot;
	int	first_quartile;
	int	i;
	int	size;

	size = a->top + 1;
	i = 0;
	pivot = get_pivot(a->stack, 0, a->top);
	first_quartile = get_first_quartile(a->stack, 0, a->top);
	while (i < size)
	{
		if (a->stack[a->top] < first_quartile)
		{
			pb(a, b, ops);
			rb(b, ops);
		}
		else if (a->stack[a->top] < pivot)
			pb(a, b, ops);
		else
			ra(a, ops);
		i++;
	}
}
