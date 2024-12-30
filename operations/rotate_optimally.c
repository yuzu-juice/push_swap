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

void	rotate_optimally(t_stack *stack, t_list *ops, t_rot rots, size_t count)
{
	if ((stack->top + 1) / 2 < (int)count)
		rotate_n_times(rots.forward, stack, ops, stack->top + 1 - count);
	else
		rotate_n_times(rots.reverse, stack, ops, count);
}
