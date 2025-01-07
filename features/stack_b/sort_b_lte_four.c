/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_lte_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:09:45 by takitaga          #+#    #+#             */
/*   Updated: 2025/01/08 00:10:28 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_b_lte_four(t_stacks *stacks, t_list *ops)
{
	t_stack	*b;
	int		size;

	b = &stacks->b;
	size = b->top - b->bottom + 1;
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_b_two(stacks, ops);
	else if (size == 3)
		sort_b_three(stacks, ops);
	else if (size == 4)
		sort_b_four(stacks, ops);
}
