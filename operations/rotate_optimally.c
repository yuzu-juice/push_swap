/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_optimally.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:34:32 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/30 21:40:46 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a_opt(t_stacks *stacks, t_list *ops, t_rot rots, size_t count)
{
	t_stack	*a;

	a = &stacks->a;
	if ((a->top + 1) / 2 < (int)count)
		apply_n_times(rots.forward, stacks, ops, a->top + 1 - count);
	else
		apply_n_times(rots.reverse, stacks, ops, count);
}

void	rotate_b_opt(t_stacks *stacks, t_list *ops, t_rot rots, size_t count)
{
	t_stack	*b;

	b = &stacks->b;
	if ((b->top + 1) / 2 < (int)count)
		apply_n_times(rots.forward, stacks, ops, b->top + 1 - count);
	else
		apply_n_times(rots.reverse, stacks, ops, count);
}
