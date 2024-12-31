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

void	apply_n_times(t_op op, t_stacks *stacks, t_list *ops, size_t n)
{
	while (n > 0)
	{
		op(stacks, ops);
		n--;
	}
}
