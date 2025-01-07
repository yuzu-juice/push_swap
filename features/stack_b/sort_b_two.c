/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:10:35 by takitaga          #+#    #+#             */
/*   Updated: 2025/01/08 00:11:25 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_b_two(t_stacks *stacks, t_list *ops)
{
	t_stack	*b;

	b = &stacks->b;
	if (b->stack[b->top] < b->stack[b->top - 1])
		sb(stacks, ops);
}
