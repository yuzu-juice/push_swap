/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+s#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:11:30 by takitaga          #+#    #+#             */
/*   Updated: 2025/01/08 00:16:44 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_b_only_three(t_stacks *stacks, t_list *ops, int stack[3])
{
	if (stack[0] < stack[1] && stack[0] < stack[2])
		sort_b_two(stacks, ops);
	else if (stack[2] < stack[0] && stack[2] < stack[1])
	{
		rb(stacks, ops);
		sort_b_two(stacks, ops);
	}
	else if (stack[1] < stack[0] && stack[1] < stack[2])
	{
		rrb(stacks, ops);
		sort_b_two(stacks, ops);
	}
}

static void	handle_sort_three(t_stacks *stacks, t_list *ops, int stack[3])
{
	if (stack[0] < stack[1] && stack[0] < stack[2])
		sort_b_two(stacks, ops);
	else if (stack[1] < stack[0] && stack[1] < stack[2])
	{
		rb(stacks, ops);
		sort_b_two(stacks, ops);
		rrb(stacks, ops);
		sort_b_two(stacks, ops);
	}
	else if (stack[2] < stack[0] && stack[2] < stack[1])
	{
		sb(stacks, ops);
		sort_b_three(stacks, ops);
	}
}

void	sort_b_three(t_stacks *stacks, t_list *ops)
{
	int		tmp_stack[3];
	t_stack	*b;

	b = &stacks->b;
	ft_memmove(tmp_stack, &b->stack[b->top - 2], sizeof(int) * 3);
	if (b->top == 2 && b->bottom == 0)
	{
		sort_b_only_three(stacks, ops, tmp_stack);
		return ;
	}
	handle_sort_three(stacks, ops, tmp_stack);
}
