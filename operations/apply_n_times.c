/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_n_times.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:36:29 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/30 16:50:12 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_n_times(t_push_op op, t_stacks *stacks, t_list *ops, size_t n)
{
	while (n--)
		op(stacks->a, stacks->b, ops);
}

void	swap_n_times(t_swap_op op, t_stack *stack, t_list *ops, size_t n)
{
	while (n--)
		op(stack, ops);
}

void	rotate_n_times(t_rot_op op, t_stack *stack, t_list *ops, size_t n)
{
	while (n--)
		op(stack, ops);
}
