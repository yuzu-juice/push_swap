/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:46:35 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/31 12:46:47 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_a_two(t_stacks *stacks, t_list *ops)
{
	t_stack	*a;

	a = &stacks->a;
	if (a->stack[a->top] > a->stack[a->top - 1])
		sa(stacks, ops);
}
